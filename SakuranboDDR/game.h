#pragma once

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
		Beat(1000, 'L'),
		Beat(1000, 'U'),
		Beat(1000, 'D'),
		Beat(1000, 'R'),
		Beat(2000, 'D'),
		Beat(3000, 'D'),
		Beat(4000, 'D'),
		Beat(5000, 'D'),
		Beat(6000, 'L'),
		Beat(6000, 'U'),
		Beat(6000, 'D'),
		Beat(6000, 'R'),
		Beat(7000, 'D'),
		Beat(7000, 'D'),
		Beat(7000, 'D'),
		Beat(7000, 'D'),
		Beat(8000, 'L'),
		Beat(8000, 'U'),
		Beat(8000, 'D'),
		Beat(8000, 'R'),
		Beat(9000, 'D'),
		Beat(10000, 'D'),
		Beat(10000, 'D'),
		Beat(10000, 'D'),
		Beat(10000, 'L'),
		Beat(11000, 'U'),
		Beat(11000, 'D'),
		Beat(11000, 'R'),
		Beat(12000, 'D'),
		Beat(12000, 'D'),
		Beat(12000, 'D'),
		Beat(12000, 'D'),
		Beat(13000, 'L'),
		Beat(13000, 'U'),
		Beat(13000, 'D'),
		Beat(13000, 'R'),
		Beat(14000, 'D'),
		Beat(14000, 'D'),
		Beat(14000, 'D'),
		Beat(14000, 'D'),
		Beat(15000, 'L'),
		Beat(15000, 'U'),
		Beat(15000, 'D'),
		Beat(15000, 'R'),
		Beat(16000, 'D'),
		Beat(16000, 'D'),
		Beat(16000, 'D'),
		Beat(16000, 'D'),
		Beat(17000, 'L'),
		Beat(17000, 'U'),
		Beat(17000, 'D'),
		Beat(17000, 'R'),
		Beat(18000, 'D'),
		Beat(18000, 'D'),
		Beat(18000, 'D'),
		Beat(18000, 'D'),
		Beat(19000, 'L'),
		Beat(19000, 'U'),
		Beat(19000, 'D'),
		Beat(19000, 'R'),
		Beat(20000, 'D'),
		Beat(20000, 'D'),
		Beat(20000, 'D'),
		Beat(20000, 'D'),
		Beat(21000, 'L'),
		Beat(21000, 'U'),
		Beat(21000, 'D'),
		Beat(21000, 'R'),
		Beat(22000, 'D'),
		Beat(23000, 'D'),
		Beat(24000, 'D'),
		Beat(25000, 'D'),
		Beat(26000, 'L'),
		Beat(26000, 'U'),
		Beat(26000, 'D'),
		Beat(22600, 'R'),
		Beat(27000, 'D'),
		Beat(27000, 'D'),
		Beat(27000, 'D'),
		Beat(27000, 'D'),
		Beat(28000, 'L'),
		Beat(28000, 'U'),
		Beat(28000, 'D'),
		Beat(28000, 'R'),
		Beat(29000, 'D'),
		Beat(31000, 'D'),
		Beat(31000, 'D'),
		Beat(30000, 'D'),
		Beat(30000, 'L'),
		Beat(31000, 'U'),
		Beat(31000, 'D'),
		Beat(31000, 'R'),
		Beat(32000, 'D'),
		Beat(32000, 'D'),
		Beat(32000, 'D'),
		Beat(32000, 'D'),
		Beat(33000, 'L'),
		Beat(33000, 'U'),
		Beat(33000, 'D'),
		Beat(33000, 'R'),
		Beat(34000, 'D'),
		Beat(34000, 'D'),
		Beat(34000, 'D'),
		Beat(34000, 'D'),
		Beat(35000, 'L'),
		Beat(35000, 'U'),
		Beat(35000, 'D'),
		Beat(35000, 'R'),
		Beat(36000, 'D'),
		Beat(36000, 'D'),
		Beat(36000, 'D'),
		Beat(36000, 'D'),
		Beat(37000, 'L'),
		Beat(37000, 'U'),
		Beat(37000, 'D'),
		Beat(37000, 'R'),
		Beat(38000, 'D'),
		Beat(38000, 'D'),
		Beat(38000, 'D'),
		Beat(38000, 'D'),
		Beat(39000, 'L'),
		Beat(39000, 'U'),
		Beat(39000, 'D'),
		Beat(39000, 'R'),
		Beat(39500, 'D'),
		Beat(39500, 'D'),
		Beat(39500, 'D'),
		Beat(39500, 'D'),
	};

	
public:
	Game(int width, int height);

	// 인트로 화면
	void startGame();
	void controlPage();

	// 게임 화면
	void runGame(int level);
	void drawGame(int level);
	void drawNote(int i);

	void dropNotes();
};
#endif