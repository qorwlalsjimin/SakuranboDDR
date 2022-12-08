#include "game.h"
#include "moving_note.h"
#include "Beat.h"
#include <Windows.h>

#define NODE_WIDTH 72;
#define NODE_HEIGHT 72;
char keycode = 'B'; // 타이밍에 맞춰 키보드를 누르지 못할때의 값

//화면에 따른 index
enum PAGE_TYPE {
	intro, game_easy, game_hard, ending
};

//타이밍에 따른 index
enum TIMING_TYPE {
	none, great, good, bad
};

//Game 생성자
Game::Game(int width, int height) {
	cout << "생성자 실행" << endl;

	// 윈도우창에서 커서 숨김
	ShowCursor(false);

	// 윈도우창 가로세로 길이
	WINDOW_WIDTH = width;
	WINDOW_HEIGHT = height;

	// 현재 화면 정보
	crtPage = PAGE_TYPE::intro;

	// 노드 떨어질지 말지
	isMovingNode = true;

	// 윈도우창 실행
	window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		"Dance Dance Revolution",
		Style::Close);
	window.setFramerateLimit(60);

	// intro page 이미지 준비
	tIntro.loadFromFile("Images/screen_intro.png");
	sIntro.setTexture(tIntro);

	// game page 이미지 준비
	tGame_easy.loadFromFile("Images/screen_game.png");
	sGame_easy.setTexture(tGame_easy);

	tGame_hard.loadFromFile("Images/screen_game_hard.jpg");
	sGame_hard.setTexture(tGame_hard);
	// sprite와 texture의 크기가 다를때에는: .setTextureRect(sf::IntRect(, , , ));

	// ending page 이미지 준비
	tEnding.loadFromFile("Images/screen_ending.jpg");
	sEnding.setTexture(tEnding);

	// 판정 이미지 준비
	tGreat.loadFromFile("Images/great.png");
	tGood.loadFromFile("Images/good.png");
	tBad.loadFromFile("Images/bad.png");
	sGreat.setTexture(tGreat);
	sGood.setTexture(tGood);
	sBad.setTexture(tBad);

	// 판정 이미지 보여줄 위치 설정
	sGreat.setPosition(230.f, 340.f);
	sGood.setPosition(230.f, 340.f);
	sBad.setPosition(230.f, 340.f);

	// fixed_node 객체 생성
	tFixedNode.loadFromFile("Images/arrow_fixed.png");
	fixed_node = new FixedNote[4];
	fill_n(fixed_node, 4, FixedNote(&tFixedNode, WINDOW_WIDTH, WINDOW_HEIGHT));

	tFixedNode_event.loadFromFile("Images/arrow_event.png");

	// 올라오는 화살표 이미지 입히기
	tMovingNode.loadFromFile("Images/arrow_moving.png");

	// 올라오는 화살표 배열 깨끗하게 지워주기
	moving_node.clear();

	// 올라오는 화살표 배열에 값 넣어주기
	dropNotes(1);

	// 폰트 불러오기
	if (font.loadFromFile("font/neodgm.ttf")) cout << "폰트 불러오기 성공" << endl;
}

// 점수 텍스트 띄워주는 메서드
int Game::textPrint(Text& textMsg, Font& font, int size,
	float x, float y, const Color& color, string p)
{
	textMsg.setFont(font);             //폰트
	textMsg.setCharacterSize(size);    //크기 
	textMsg.setPosition(x, y);         //x, y 위치
	textMsg.setFillColor(color);       //색
	textMsg.setString(p); //출력할 문자열
	return 0;

};

// 올라오는 노트 데이터 배열에 삽입해주기
void Game::dropNotes(int level) { //레벨을 매개변수로 받기(추후 맵 추가를 위함)
	cout << "dropNotes 실행" << endl;
	//올라오는 화살표 시간에 맞춰 그려주기

	for (int i = 0; i < 284; i++) { //sizeof(beat_easy) / sizeof(beat_easy[0]){
		moving_node.push_back(MovingNote(&tMovingNode, beat_easy[i].getNoteName()));
	}
}

/*게임 실행 - 윈도우창 열려있는 동안
---------------------------------*/
void Game::startGame() {
	cout << "startGame 실행" << endl;

	// crtPage에 다른 값 들어오면 끝
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

			controlPage();
		}


		// 화면 전환
		switch (crtPage) {
			//인트로 화면
			case PAGE_TYPE::intro:
				window.draw(sIntro); //배경 그려주기
				break;

			//게임 화면
			case PAGE_TYPE::game_easy:
				timer = clock(); //게임 시작 시 타이머도 시작
				runGame(1); //게임에 필요한 객체 준비
				controlPage(); 
				break;

			//엔딩 화면
			case PAGE_TYPE::ending:
				window.draw(sEnding);
				break;
		}

		window.display();
	}
}

// 키보드 이벤트로 crtPage 값 조정
void Game::controlPage() {
	if (event.type == Event::KeyPressed) {
		switch (event.key.code) {
		case Keyboard::Space: //쉬운 버전으로 이동
			crtPage = PAGE_TYPE::game_easy;
			cout << "쉬운 버전" << endl;
			break;
		//추후 맵 추가시 이곳에 더하기
		default:
			break;
		}
	}
}


/* DDR 게임 시작
---------------------------------*/
void Game::runGame(int level) {
	cout << "runGame 실행" << endl;

	// 음악 시작
	if (!bgm.openFromFile("Sound/playbgm.wav"))
		cout << "playbgm.wav파일을 열 수 없습니다." << endl;
	bgm.play();


	while (window.isOpen()) {

		//if (duration > 1500) // 게임 엔딩 빨리 보고 싶을때
		// 음악 재생 시간이 끝나면 게임 플레이도 끝내기
		if (duration > (int)bgm.getDuration().asSeconds() * 1000)
		{
			endPage(); //엔딩화면으로 이동
			break;
		}

		//추후 맵 추가시 이곳에 switch문으로
		drawGame(1);

		window.display();

	}
}

// 게임에 필요한 그래픽 준비
void Game::drawGame(int level) {
	// 배경 그려주기
	window.draw(sGame_easy);

	// 점수 출력
	textPrint(textScore, font, 40, 345, 715, Color::White, to_string(score));

	// 고정된 화살표 위치, 회전값 조절
	fixed_node[0].setPosition(220.f, 130.f);
	fixed_node[1].setPosition(342.f, 130.f); //+122
	fixed_node[2].setPosition(464.f, 130.f); //+122
	fixed_node[3].setPosition(586.f, 130.f); //+122

	fixed_node[1].setRotation(270.f);
	fixed_node[2].setRotation(90.f);
	fixed_node[3].setRotation(180.f);

	// 고정된 화살표 화면에 올리기
	for (int j = 0; j < 4; j++)
		window.draw(fixed_node[j]); //고정된 흰색 화살표 그려주기

	// 게임 플레잉 시간
	duration = clock() - timer;

	//올라오는 화살표 시간에 맞춰 그려주기
	for (int i = 0; i < 284; i++) { //sizeof(beat_easy) / sizeof(beat_easy[0])
		if (beat_easy[i].getTime() <= duration) //데이터에 입력된 시간이 타이머 시간에 다다랐을때
		{
			moving_node[i].update(-18); //18씩 위로 올라감 
			window.draw(moving_node[i]); //올라오는 화살표 그려주기
		}
	}

	//★ 판정
	for (auto& iter : moving_node) {
		// 점수 출력
		window.draw(textScore);

		// 타이밍 못맞추면 자동 bad 판정
		keycode = 'B';

		if (isMovingNode) {
			//* 화살표 충돌 판정: 목표 화살표와 움직이는 화살표의 y좌표값 차이로 판정
			// 화살표 놓쳤을때-BAD
			if (iter.getMovingNoteY() - fixed_node[0].getFixedNoteY() <= 0) {
				iter.setFillColor(sf::Color::Red);
			}
			
			// 목표 화살표를 살짝 넘어선 윗 부분-GOOD
			else if (iter.getMovingNoteY() - fixed_node[0].getFixedNoteY() <= 10) {
				iter.setFillColor(sf::Color::Yellow);

				// 플레이어가 입력한 키보드값 받기
				switch (event.key.code) {
					case Keyboard::Left:
						keycode = 'J';
						break;
					case Keyboard::Down:
						keycode = 'K';
						break;
					case Keyboard::Up:
						keycode = 'I';
						break;
					case Keyboard::Right:
						keycode = 'L';
						break;
				}

				// 누른 키보드키와 올라오는 화살표의 방향이 같으면 판정
				while (window.pollEvent(event)) { // 키보드 눌렀을때만 실행
					if (keycode == iter.getArrow()) { // 키보드키와 화살표 방향 비교
						score += 1000; // 점수 획득
						timingImage = TIMING_TYPE::good; // 타이밍 단계 보여주는 이미지
						break;
					}
					else { //키보드키와 화살표 방향이 다를때
						score += 0;
						timingImage = TIMING_TYPE::bad;
					}

				}
			}

			//목표 화살표 부분-GREAT
			else if (iter.getMovingNoteY() - fixed_node[0].getFixedNoteY() <= 200) {
				iter.setFillColor(sf::Color::Green);

				switch (event.key.code) {
					case Keyboard::Left:
						keycode = 'J';
						break;
					case Keyboard::Down:
						keycode = 'K';
						break;
					case Keyboard::Up:
						keycode = 'I';
						break;
					case Keyboard::Right:
						keycode = 'L';
						break;
				}

				while (window.pollEvent(event)) {
					if (keycode == iter.getArrow()) {
						score += 3000;
						timingImage = TIMING_TYPE::great;
						break;
					}
					else {
						score += 0;
						timingImage = TIMING_TYPE::bad;
					}

				}
			}

			//목표 화살표보다 밑 부분-GOOD
			else if (iter.getMovingNoteY() - fixed_node[0].getFixedNoteY() <= 450) {
				iter.setFillColor(sf::Color::Yellow);

				switch (event.key.code) {
					case Keyboard::Left:
						keycode = 'J';
						break;
					case Keyboard::Down:
						keycode = 'K';
						break;
					case Keyboard::Up:
						keycode = 'I';
						break;
					case Keyboard::Right:
						keycode = 'L';
						break;
				}
				while (window.pollEvent(event)) {
					if (keycode == iter.getArrow()) {
						score += 1000;
						timingImage = TIMING_TYPE::good;
						break;
					}
					else {
						score += 0;
						timingImage = TIMING_TYPE::bad;
					}

				}
			}

			//목표 화살표보다 훨씬 밑 부분-BAD
			else if (iter.getMovingNoteY() - fixed_node[0].getFixedNoteY() > 450) {
				iter.setFillColor(sf::Color::Red);

				switch (event.key.code) {
					case Keyboard::Left:
						keycode = 'J';
						break;
					case Keyboard::Down:
						keycode = 'K';
						break;
					case Keyboard::Up:
						keycode = 'I';
						break;
					case Keyboard::Right:
						keycode = 'L';
						break;
				}

				while (window.pollEvent(event)) {
					if (keycode == iter.getArrow()) {
						score += 0;
						timingImage = TIMING_TYPE::bad;
					}
				}

			}


		}
	}

	// 타이밍 단계 알려주는 이미지 보여주기
	switch (timingImage) { // 변수에 넣어서 어떤 이미지를 보여줄지 저장해둔 상태
		case TIMING_TYPE::none: 
			break;
		case TIMING_TYPE::great: // 해당하는 값에 따라서
			window.draw(sGreat);
			break;
		case TIMING_TYPE::good:	 // 해당하는 이미지를 draw해준다
			window.draw(sGood);
			break;
		case TIMING_TYPE::bad:   // position은 생성자에서 처리
			window.draw(sBad);
			break;
	}

	// 텍스트 보여주기
	window.draw(textScore);
}


/* 엔딩 보여주기
---------------------------------*/
void Game::endPage() {
	// 게임이 종료되었을 때 실행

	window.clear();
	window.draw(sEnding);

	textPrint(textScore, font, 100, 50, 10, Color::White, to_string(score));

	window.draw(textScore);
	window.display();

	// 쉬게 하기! 안 하면 게임 화면이랑 왔다갔다 함
	Sleep(5000);
}