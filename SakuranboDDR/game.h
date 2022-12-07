﻿#pragma once

// 헤더파일 중복 방지
#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <vector> 
#include <ctime>

#include "fixed_note.h"
#include "moving_note.h"
#include "Beat.h"

using namespace std;
using namespace sf;

class Game {
private:
	// window창 가로 세로 폭
	int WINDOW_WIDTH, WINDOW_HEIGHT;

	//// 노드 떨어지는 속도
	//int SPEED;

	// 노드 떨어질지 말지
	bool isMovingNode;

	// 시작 화면 판단
	bool isStartPage;
	int crtPage;

	// window
	RenderWindow window;

	// intro page
	Texture tIntro;
	Sprite sIntro;

	// game page
	Texture tGame_easy;
	Sprite sGame_easy;

	Texture tGame_hard;
	Sprite sGame_hard;

	// ending page
	Texture tEnding;
	Sprite sEnding;

	// 키보드 event
	Event event;

	// bgm
	Music bgm;

	// fixed_node
	FixedNote* fixed_node;
	Texture tFixedNode;

	// moving_node
	vector<MovingNote> moving_node; // 올라오는 모든 노드를 담는 배열
	Texture tMovingNode;

	// 타이머
	clock_t  timer;
	double duration;

	// 노트 악보
	Beat beat_easy[200] = {
		Beat(9000, 'U'),
		Beat(9300, 'U'),
		Beat(9600, 'U'),
		Beat(9900, 'U'),
		Beat(10500, 'D'),
		Beat(10800, 'D'),
		Beat(11100, 'D'),
		Beat(11400, 'D'),
		Beat(-1, 'U'),
	};

	Beat beat_hard[200] = {
		Beat(9000, 'U'),
		Beat(9300, 'U'),
		Beat(9600, 'U'),
		Beat(9900, 'U'),
		Beat(10500, 'U'),
		Beat(10500, 'D'),
		Beat(10800, 'L'),
		Beat(10800, 'R'),
		Beat(11100, 'L'),
		Beat(11400, 'R'),
		Beat(11700, 'R'),
		Beat(12000, 'L'),
		Beat(-1, 'U'),
	};

	
public:
	Game(int width, int height);

	// 인트로 화면
	void startGame();
	void controlPage();

	// 게임 화면
	void runGame(int level);
	void drawGame(int level);
	void dropNotes(int level);
	void catchNotes();
};
#endif