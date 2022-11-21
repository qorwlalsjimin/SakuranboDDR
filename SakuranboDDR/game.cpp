#include "game.h"

//Game 생성자
Game::Game(int width, int height) {
	cout << "생성자 실행" << endl;

	WINDOW_WIDTH = width;
	WINDOW_HEIGHT = height;

	isStartPage = true;

	// background image
	tBackground.loadFromFile("Images/screen_game.png");
	tBackground.setSmooth(true);

	sBackground.setTexture(tBackground);
	// sprite와 texture의 크기가 다를때에는: .setTextureRect(sf::IntRect(, , , ));

	// window
	window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		"Dance Dance Revolution",
		Style::Close);
	window.setFramerateLimit(60);

	// intro page
	tStartpage.loadFromFile("Images/screen_intro.png");
	sStartpage.setTexture(tStartpage);

	//if (!bgm.openFromFile("Sound/playbgm.wav"))
	//	cout << "playbgm.wav파일을 열 수 없습니다." << endl;
	//bgm.setVolume(20.0);

	// fixed_node
	tFixedNode.loadFromFile("Images/arrow_left.png");
	fill_n(fixed_node, 4, FixedNode(&tFixedNode, WINDOW_WIDTH, WINDOW_HEIGHT));
}

/* 인트로 화면
---------------------------------*/
void Game::startGame() {
	cout << "startGame 실행" << endl;

	while (window.isOpen() && isStartPage) {
		// action
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

			startPage();
		}

		// draw start page
		window.draw(sStartpage);
		window.display();
	}

	runGame();
}

// 게임 시작 (enter 키 이벤트)
void Game::startPage() {
	//cout << "startPage 실행" << endl;

	if (event.type == Event::KeyPressed) {
		switch (event.key.code) {
		case Keyboard::Enter:
			isStartPage = false;
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
	window.draw(sBackground);

	fixed_node[0].setPosition(220.f, 126.f);
	fixed_node[1].setPosition(343.f, 126.f);
	fixed_node[2].setPosition(465.f, 126.f);
	fixed_node[3].setPosition(587.f, 126.f);

	fixed_node[1].setRotation(90.f);
	fixed_node[2].setRotation(180.f);
	fixed_node[3].setRotation(270.f);

	for(int i = 0; i<4; i++)
		window.draw(fixed_node[i]);

	startPage();
}