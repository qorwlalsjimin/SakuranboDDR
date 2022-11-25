#include "game.h"
#include <Windows.h>

enum page_type {
	intro, game, ending
};

//Game 생성자
Game::Game(int width, int height) {
	cout << "생성자 실행" << endl;

	ShowCursor(false);

	WINDOW_WIDTH = width;
	WINDOW_HEIGHT = height;

	crtPage = page_type::intro;


	// window
	window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		"Dance Dance Revolution",
		Style::Close);
	window.setFramerateLimit(60);


	// intro page
	tIntro.loadFromFile("Images/screen_intro.png");
	sIntro.setTexture(tIntro);

	// game page
	tGame.loadFromFile("Images/screen_game.png");
	tGame.setSmooth(true);
	sGame.setTexture(tGame);
	// sprite와 texture의 크기가 다를때에는: .setTextureRect(sf::IntRect(, , , ));

	// game page
	tEnding.loadFromFile("Images/screen_ending.jpg");
	tEnding.setSmooth(true);
	sEnding.setTexture(tEnding);

	// fixed_node
	tFixedNode.loadFromFile("Images/arrow_left.png");
	fixed_node = new FixedNode[4];
	fill_n(fixed_node, 4, FixedNode(&tFixedNode, WINDOW_WIDTH, WINDOW_HEIGHT));
}

/* 인트로 화면
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

			cout << "이거 실행 안 되나" << endl;
			startPage();
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
			startPage();
			break;
		case page_type::ending :
			window.draw(sEnding);
			window.display();
			break;
		}
	}
}

// 게임 시작 (enter 키 이벤트)
void Game::startPage() {
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


/* Game Loop
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

void Game::drawGame() {
	window.draw(sGame);

	fixed_node[0].setPosition(220.f, 126.f);
	fixed_node[1].setPosition(343.f, 126.f);
	fixed_node[2].setPosition(465.f, 126.f);
	fixed_node[3].setPosition(587.f, 126.f);

	fixed_node[1].setRotation(90.f);
	fixed_node[2].setRotation(180.f);
	fixed_node[3].setRotation(270.f);

	for (int i = 0; i < 4; i++)
		window.draw(fixed_node[i]);

	startPage();
}