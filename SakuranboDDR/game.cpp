#include "game.h"
#include "Beat.h"
#include <Windows.h>

#define NODE_WIDTH 72;
#define NODE_HEIGHT 72;

enum page_type { //대문자
	intro, game_easy, game_hard, ending
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
	crtPage = page_type::intro;

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

	// fixed_node 객체 생성
	tFixedNode.loadFromFile("Images/arrow_fixed.png");
	fixed_node = new FixedNote[4];
	fill_n(fixed_node, 4, FixedNote(&tFixedNode, WINDOW_WIDTH, WINDOW_HEIGHT));

	// 올라오는 화살표 이미지 입히기
	tMovingNode.loadFromFile("Images/arrow_moving.png");

}

// 올라오는 노트 데이터
void Game::dropNotes(int level) {
	cout << "dropNotes 실행" << endl;
	//올라오는 화살표 시간에 맞춰 그려주기

	switch (level) {
		case 1:
			for (int i = 0; i < 200; i++) //sizeof(beat_easy) / sizeof(beat_easy[0])
				moving_node.push_back(MovingNote(&tMovingNode, beat_easy[i].getNoteName()));
			break;
		case 2:
			for (int i = 0; i < 200; i++) //sizeof(beat_hard) / sizeof(beat_hard[0])
				moving_node.push_back(MovingNote(&tMovingNode, beat_hard[i].getNoteName()));
			break;
	}//switch
	
}//dropNotes

/*게임 실행 - 윈도우창 열려있는 동안
---------------------------------*/
void Game::startGame() {
	cout << "startGame 실행" << endl;

	// crtPage에 다른 값 들어오면 끝
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			controlPage();
		}
		
		// 화면 전환
		switch (crtPage) {
		case page_type::intro :
			window.draw(sIntro);
			break;

		case page_type::game_easy :
			timer = clock(); //게임 시작 시 타이머도 시작
			window.draw(sGame_easy);
			runGame(1);
			controlPage();
			break;

		case page_type::game_hard :
			timer = clock(); //게임 시작 시 타이머도 시작
			window.draw(sGame_hard);
			runGame(2);
			controlPage();
			break;

		case page_type::ending :
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
		case Keyboard::G: //쉬운 버전으로 이동
			crtPage = page_type::game_easy;
			cout << "쉬운 버전" << endl;
			break;

		case Keyboard::H: //어려운 버전으로 이동
			crtPage = page_type::game_hard;
			cout << "어려운 버전" << endl;
			break;

		case Keyboard::Enter: //엔딩 화면으로 이동
			cout << "엔딩" << endl;
			crtPage = page_type::ending;
			break;

		default:
			break;
		}
	}
}

void Game::catchNotes() {
	if (event.type == Event::KeyPressed) {
		switch (event.key.code) {
		case Keyboard::J:
			cout << "←" << endl;
			break;
		case Keyboard::K:
			cout << "↓" << endl;
			cout << fixed_node[1].getFillColor().toInteger() << endl;
			break;
		case Keyboard::I:
			cout << "↑" << endl;
			cout << fixed_node[2].getFillColor().toInteger() << endl;
			break;
		case Keyboard::L:
			cout << "→" << endl;
			cout << fixed_node[3].getFillColor().toInteger() << endl;
			break;

		default:
			break;
		}
	}
}

/* DDR 게임 시작
---------------------------------*/
void Game::runGame(int level) {
	cout << "runGame 실행" << endl;

	if (!bgm.openFromFile("Sound/playbgm.wav"))
		cout << "playbgm.wav파일을 열 수 없습니다." << endl;
	bgm.play();
	bgm.setLoop(true);

	moving_node.clear();

	dropNotes(level);
	while (window.isOpen()) {
		drawGame(level);
		window.display();

		// 음악 재생 시간이 되면 끝내기
		if (duration > (int)bgm.getDuration().asSeconds() * 1000)
			break;

		// 화살표 키 이벤트
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			catchNotes();
		}
	}
}

// 게임에 필요한 그래픽 준비
void Game::drawGame(int level) {
	switch (level) {
	case 1:
		window.draw(sGame_easy);
		break;
	case 2:
		window.draw(sGame_hard);
		break;

	}

	// 고정된 화살표
	fixed_node[0].setPosition(220.f, 130.f);
	fixed_node[1].setPosition(342.f, 130.f); //+122
	fixed_node[2].setPosition(464.f, 130.f); //+122
	fixed_node[3].setPosition(586.f, 130.f); //+122

	fixed_node[1].setRotation(270.f);
	fixed_node[2].setRotation(90.f);
	fixed_node[3].setRotation(180.f);

	// 화면에 올리기
	for (int i = 0; i < 4; i++) 
		window.draw(fixed_node[i]); //고정된 흰색 화살표 그려주기

	switch (level) {
	case 1:
		duration = clock() - timer;
		//cout << duration << endl;
		//올라오는 화살표 시간에 맞춰 그려주기
		for (int i = 0; i < 200; i++) { //sizeof(beat_easy) / sizeof(beat_easy[0])
			if (beat_easy[i].getTime() <= duration && beat_easy[i].getTime() != -1)
			{
				moving_node[i].update(-18); //135 기준으로 사라져야함
				window.draw(moving_node[i]);
			}
		}
		break;

	case 2:
		duration = clock() - timer;
		//cout << duration << endl;
		//올라오는 화살표 시간에 맞춰 그려주기
		for (int i = 0; i < 200; i++) { //sizeof(beat_hard) / sizeof(beat_hard[0])
			if (beat_hard[i].getTime() <= duration && beat_hard[i].getTime() != -1)
			{
				moving_node[i].update(-18); //135 기준으로 사라져야함
				window.draw(moving_node[i]);
			}
		}
		break;

	}

	for (auto& iter : moving_node) {
		if (isMovingNode) {

			//* 화살표 충돌 판정: 목표 화살표와 움직이는 화살표의 y좌표값 차이로 판정
			//목표 화살표를 넘어선 윗 부분 
			if (iter.getMovingNoteY() - fixed_node[0].getFixedNoteY() <= 10) { 
				iter.setFillColor(sf::Color::Yellow);
			}

			//목표 화살표 부분
			else if (iter.getMovingNoteY() - fixed_node[0].getFixedNoteY() <= 200) {
				iter.setFillColor(sf::Color::Green);
			}

			//목표 화살표보다 밑 부분
			else if (iter.getMovingNoteY() - fixed_node[0].getFixedNoteY() <= 500) {
				iter.setFillColor(sf::Color::Yellow);
			}

			//목표 화살표보다 훨씬 밑 부분
			else{
				iter.setFillColor(sf::Color::Red);
			}

		}
	}

}