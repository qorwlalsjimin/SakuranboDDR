#include "game.h"
#include <Windows.h>

enum page_type {
	intro, game, ending
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

	// 윈도우창 실행
	window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		"Dance Dance Revolution",
		Style::Close);
	window.setFramerateLimit(60);

	// intro page 이미지 준비
	tIntro.loadFromFile("Images/screen_intro.png");
	sIntro.setTexture(tIntro);

	// game page 이미지 준비
	tGame.loadFromFile("Images/screen_game.png");
	sGame.setTexture(tGame);
	// sprite와 texture의 크기가 다를때에는: .setTextureRect(sf::IntRect(, , , ));

	// game page 이미지 준비
	tEnding.loadFromFile("Images/screen_ending.jpg");
	sEnding.setTexture(tEnding);

	// fixed_node 객체 생성
	//tFixedNode.loadFromFile("Images/arrow_fixed.png");
	fixed_node = new FixedNode[4];
	fill_n(fixed_node, 4, FixedNode(&tFixedNode, WINDOW_WIDTH, WINDOW_HEIGHT));

	// moving_node 객체생성
	//tMovingNode.loadFromFile("Images/arrow_moving.png");
	//moving_node = new MovingNode[4];
}

/*게임 실행 - 윈도우창 열려있는 동안
---------------------------------*/
void Game::startGame() {
	cout << "startGame 실행" << endl;

	// crtPage에 다른 값 들어오면 끝
	while (window.isOpen()) {
		//cout << "crtPage: " << crtPage << endl;

		//
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
			window.display();
			break;
		case page_type::game :
			window.draw(sGame);
			window.display();
			runGame();
			controlPage();
			break;
		case page_type::ending :
			window.draw(sEnding);
			window.display();
			break;
		}
	}
}

// 키보드 이벤트로 crtPage 값 조정
void Game::controlPage() {
	if (event.type == Event::KeyPressed) {
		cout << "키눌럿는뎅 실행-" << endl;
		switch (event.key.code) {
		case Keyboard::Enter:
			cout << "엔터!" << endl;
			crtPage = page_type::game;
			cout << "crtPage: " << crtPage << endl;
			break;
		case Keyboard::A:
			//엔딩 화면으로 이동
			cout << "A!" << endl;
			crtPage = page_type::ending;
			cout << "crtPage: " << crtPage << endl;
			break;
		default:
			break;
		}
	}
}


/* DDR 게임 시작
---------------------------------*/
void Game::runGame() {
	if (!bgm.openFromFile("Sound/playbgm.wav"))
		cout << "playbgm.wav파일을 열 수 없습니다." << endl;
	bgm.play();
	bgm.setLoop(true);

	cout << "runGame 실행" << endl;

	while (window.isOpen()) {

		/* Draw */
		drawGame();
		window.display();
	}

}

// 게임에 필요한 그래픽 준비
void Game::drawGame() {
	window.draw(sGame);

	// 고정된 화살표
	fixed_node[0].setPosition(220.f, 126.f);
	fixed_node[1].setPosition(342.f, 126.f); //+122
	fixed_node[2].setPosition(464.f, 126.f); //+122
	fixed_node[3].setPosition(586.f, 126.f); //+122

	fixed_node[1].setRotation(90.f);
	fixed_node[2].setRotation(180.f);
	fixed_node[3].setRotation(270.f);

	// 움직이는 화살표
	moving_node.push_back(MovingNode(&tMovingNode, 170.f, 206.f, 0.f));
	moving_node.push_back(MovingNode(&tMovingNode, 292.f, 206.f, 0.f));
	moving_node.push_back(MovingNode(&tMovingNode, 414.f, 206.f, 0.f));
	moving_node.push_back(MovingNode(&tMovingNode, 536.f, 206.f, 0.f));
	
	
	//467
	// 화면에 올리기
	for (int i = 0; i < 4; i++)
		window.draw(fixed_node[i]);


	for (auto& iter : moving_node)
		window.draw(iter);
}