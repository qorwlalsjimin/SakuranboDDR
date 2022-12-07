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
	//키보드로 입력한 값
	char arrowPressed;

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

	// moving_note의 인덱스
	int i = 0;

	// 점수
	int score = 0;

	int gap = 300;
	// 노트 악보
	Beat beat_easy[200] = {
		Beat(9000, 'J'),
		Beat(9300, 'J'),
		Beat(9600, 'J'),
		Beat(9900, 'J'),
		Beat(10500, 'K'),
		Beat(10800, 'K'),
		Beat(11100, 'K'),
		Beat(11400, 'K'),
		Beat(11700, 'I'),
		Beat(12000, 'I'),
		Beat(13000, 'I'),
		Beat(14000, 'I'),
		Beat(15000, 'L'),
		Beat(16000, 'L'),
		Beat(17000, 'L'),
		Beat(18000, 'L'),
		Beat(19000, 'J'),
		Beat(20000, 'J'),
		Beat(21000, 'J'),
		Beat(22000, 'J'),
		Beat(23000, 'K'),
		Beat(24000, 'K'),
		Beat(25000, 'K'),
		Beat(26000, 'K'),
		Beat(27000, 'I'),
		Beat(28000, 'I'),
		Beat(29000, 'I'),
		Beat(30000, 'I'),
		Beat(31000, 'L'),
		Beat(32000, 'L'),
		Beat(33000, 'L'),
		Beat(34000, 'L'),
		Beat(35000, 'J'),
		Beat(36000, 'J'),
		Beat(37000, 'J'),
		Beat(38000, 'J'),
		Beat(39000, 'K'),
		Beat(40000, 'K'),
		Beat(41000, 'K'),
		Beat(42000, 'K'),
		Beat(45000, 'I'),
		Beat(50000, 'I'),
		Beat(55000, 'I'),
		Beat(60000, 'I'),
		Beat(65000, 'L'),
		Beat(70000, 'L'),
		Beat(75000, 'L'),
		Beat(80000, 'L'),
		Beat(85000, 'L'),
		Beat(90000, 'L'),
		Beat(95000, 'L'),
		Beat(100000, 'L'),
		Beat(135000, 'J'),
		Beat(136000, 'J'),
		Beat(137000, 'J'),
		Beat(138000, 'J'),
		Beat(139000, 'K'),
		Beat(140000, 'K'),
		Beat(141000, 'K'),
		Beat(142000, 'K'),
		Beat(145000, 'I'),
		Beat(150000, 'I'),
		Beat(155000, 'I'),
		Beat(160000, 'I'),
		Beat(165000, 'L'),
		Beat(170000, 'L'),
		Beat(175000, 'L'),
		Beat(180000, 'L'),
		Beat(-1, 'I'),
	};

	Beat beat_hard[200] = {
		Beat(9000, 'I'),
		Beat(9300, 'I'),
		Beat(9600, 'I'),
		Beat(9900, 'I'),
		Beat(10500, 'I'),
		Beat(10500, 'K'),
		Beat(10800, 'J'),
		Beat(10800, 'L'),
		Beat(11100, 'J'),
		Beat(11400, 'L'),
		Beat(11700, 'L'),
		Beat(12000, 'J'),
		Beat(-1, 'I'),
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

	void judge(int index);
};
#endif