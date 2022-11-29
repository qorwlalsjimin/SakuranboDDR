﻿#pragma once

// 헤더파일 중복 방지
#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <vector> 

#include "fixed_node.h"
#include "moving_node.h"

using namespace std;
using namespace sf;

class Game {
private:
	// window창 가로 세로 폭
	int WINDOW_WIDTH, WINDOW_HEIGHT;

	// 노드 떨어지는 속도
	int SPEED;

	// 노드 떨어질지 말지
	bool isMovingNode;

	// 판정 좌표
	int judgeX;
	int judgeY;

	// 시작 화면 판단
	bool isStartPage;
	int crtPage;

	// window
	RenderWindow window;

	// intro page
	Texture tIntro;
	Sprite sIntro;

	// game page
	Texture tGame;
	Sprite sGame;

	// ending page
	Texture tEnding;
	Sprite sEnding;

	// 키보드 event
	Event event;

	// bgm
	Music bgm;

	// fixed_node
	FixedNode* fixed_node;
	Texture tFixedNode;

	// moving_node
	vector<MovingNode> moving_node; // 올라오는 모든 노드를 담는 배열
	Texture tMovingNode;
	
public:
	Game(int width, int height);

	// 인트로 화면
	void startGame();
	void controlPage();

	// 게임 화면
	void runGame();
	void drawGame();

	void dropNotes(string grade);
};
#endif