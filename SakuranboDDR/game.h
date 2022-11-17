#pragma once

// 헤더파일 중복 방지
#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

class Game {
private:
	// window창 가로 세로 폭
	int WINDOW_WIDTH, WINDOW_HEIGHT;

	// 시작 화면 판단
	bool isStartPage;

	// window
	RenderWindow window;

	// intro page
	Texture tStartpage;
	Sprite sStartpage;

	// background image
	Texture tBackground;
	Sprite sBackground;

	// 키보드 event
	Event event;

	// bgm
	Music bgm;

public:
	Game(int width, int height);

	// 인트로 화면
	void startGame();
	void startPage();

	// 게임 화면
	void runGame();
	void drawGame();
};
#endif