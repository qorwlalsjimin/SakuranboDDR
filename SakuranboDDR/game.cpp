﻿#include "game.h"

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

	// window
	window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
				"Dance Dance Revolution",
				Style::Close);
	window.setFramerateLimit(60);

	// intro page
	tStartpage.loadFromFile("Images/screen_intro.png");
	sStartpage.setTexture(tStartpage);
}

/* 인트로 화면
---------------------------------*/
void Game::startGame(){
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
	cout << "startPage 실행" << endl;

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
	cout << "runGame 실행" << endl;

	while (window.isOpen()) {
		/* Draw */
		drawGame();
		window.display();
	}

}

void Game::drawGame() {
	window.draw(sBackground);

	startPage();
}
