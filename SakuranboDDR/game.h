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
	int crtPage; //enum의 값이 들어감

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

	// 판정 이미지
	Texture tGreat;
	Texture tGood;
	Texture tBad;
	Sprite sGreat;
	Sprite sGood;
	Sprite sBad;

	// 보여질 판정 이미지는 무엇으로 할지 판단
	int timingImage; //enum의 값이 들어감

	// 키보드 event
	Event event;

	// bgm
	Music bgm;

	// fixed_node
	FixedNote* fixed_node;
	Texture tFixedNode;
	Texture tFixedNode_event;

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
	Text textScore;
	Font font;

	int gap = 300;
	// 노트 악보
	Beat beat_easy[281] = { 
      Beat(300 * 30, 'I'),
      Beat(300 * 31, 'I'),
      Beat(300 * 32, 'I'),
      Beat(300 * 33, 'I'),

      Beat(300 * 35, 'K'),
      Beat(300 * 36, 'K'),
      Beat(300 * 37, 'K'),
      Beat(300 * 38, 'K'),

      Beat(300 * 40, 'J'),
      Beat(300 * 41, 'J'),
      Beat(300 * 42, 'J'),
      Beat(300 * 43, 'J'),

      Beat(300 * 45, 'K'),
      Beat(300 * 47, 'K'),
      Beat(300 * 48, 'K'),
      Beat(300 * 49, 'K'),

      Beat(300 * 51, 'I'),
      Beat(300 * 52, 'I'),
      Beat(300 * 53, 'I'),
      Beat(300 * 54, 'I'),

      Beat(300 * 56, 'L'),
      Beat(300 * 57, 'L'),
      Beat(300 * 58, 'L'),
      Beat(300 * 59, 'L'),

      Beat(300 * 60, 'J'),
      Beat(300 * 62, 'J'),
      Beat(300 * 63, 'J'),
      Beat(300 * 64, 'J'),

      Beat(300 * 66, 'K'),
      Beat(300 * 67, 'K'),
      Beat(300 * 68, 'K'),
      Beat(300 * 69, 'K'),

      Beat(300 * 71, 'K'),
      Beat(300 * 72, 'K'),
      Beat(300 * 73, 'I'),
      Beat(300 * 74, 'I'),

      Beat(300 * 76, 'I'),
      Beat(300 * 77, 'I'),
      Beat(300 * 78, 'L'),
      Beat(300 * 79, 'L'),

      Beat(300 * 81, 'L'),
      Beat(300 * 82, 'L'),
      Beat(300 * 83, 'J'),
      Beat(300 * 84, 'J'),

      Beat(300 * 86, 'J'),
      Beat(300 * 87, 'J'),
      Beat(300 * 88, 'K'),
      Beat(300 * 89, 'K'),

      Beat(300 * 91, 'K'),
      Beat(300 * 92, 'K'),
      Beat(300 * 93, 'I'),
      Beat(300 * 94, 'I'),

      Beat(300 * 96, 'I'),
      Beat(300 * 97, 'I'),
      Beat(300 * 98, 'L'),
      Beat(300 * 99, 'L'),

      Beat(300 * 101, 'L'),
      Beat(300 * 102, 'L'),
      Beat(300 * 103, 'L'),
      Beat(300 * 104, 'L'),

      Beat(300 * 106, 'L'),
      Beat(300 * 107, 'L'),
      Beat(300 * 108, 'J'),
      Beat(300 * 109, 'J'),

      Beat(300 * 111, 'J'),
      Beat(300 * 112, 'J'),
      Beat(300 * 113, 'K'),
      Beat(300 * 114, 'K'),

      Beat(300 * 116, 'K'),
      Beat(300 * 117, 'K'),
      Beat(300 * 118, 'I'),
      Beat(300 * 119, 'I'),

      Beat(300 * 121, 'I'),
      Beat(300 * 122, 'I'),
      Beat(300 * 123, 'L'),
      Beat(300 * 124, 'L'),

      Beat(300 * 126, 'I'),
      Beat(300 * 127, 'I'),
      Beat(300 * 128, 'I'),
      Beat(300 * 130, 'I'),

      Beat(300 * 132, 'K'),
      Beat(300 * 134, 'K'),
      Beat(300 * 136, 'K'),
      Beat(300 * 138, 'K'),

      Beat(300 * 140, 'J'),
      Beat(300 * 141, 'J'),
      Beat(300 * 142, 'J'),
      Beat(300 * 143, 'J'),

      Beat(300 * 145, 'K'),
      Beat(300 * 147, 'K'),
      Beat(300 * 148, 'K'),
      Beat(300 * 149, 'K'),

      Beat(300 * 151, 'I'),
      Beat(300 * 152, 'I'),
      Beat(300 * 153, 'I'),
      Beat(300 * 154, 'I'),

      Beat(300 * 156, 'L'),
      Beat(300 * 157, 'L'),
      Beat(300 * 158, 'L'),
      Beat(300 * 159, 'L'),

      Beat(300 * 161, 'J'),
      Beat(300 * 162, 'J'),
      Beat(300 * 163, 'J'),
      Beat(300 * 164, 'J'),

      Beat(300 * 166, 'K'),
      Beat(300 * 167, 'K'),
      Beat(300 * 168, 'K'),
      Beat(300 * 169, 'K'),

      Beat(300 * 171, 'K'),
      Beat(300 * 172, 'K'),
      Beat(300 * 173, 'I'),
      Beat(300 * 174, 'I'),

      Beat(300 * 176, 'I'),
      Beat(300 * 177, 'I'),
      Beat(300 * 178, 'L'),
      Beat(300 * 179, 'L'),

      Beat(300 * 181, 'L'),
      Beat(300 * 182, 'L'),
      Beat(300 * 183, 'J'),
      Beat(300 * 184, 'J'),

      Beat(300 * 186, 'J'),
      Beat(300 * 187, 'J'),
      Beat(300 * 188, 'K'),
      Beat(300 * 189, 'K'),

      Beat(300 * 191, 'K'),
      Beat(300 * 192, 'K'),
      Beat(300 * 193, 'I'),
      Beat(300 * 194, 'I'),

      Beat(300 * 196, 'I'),
      Beat(300 * 197, 'I'),
      Beat(300 * 198, 'L'),
      Beat(300 * 199, 'L'),

      Beat(300 * 201, 'L'),
      Beat(300 * 202, 'L'),
      Beat(300 * 203, 'L'),
      Beat(300 * 204, 'L'),

      Beat(300 * 206, 'L'),
      Beat(300 * 207, 'L'),
      Beat(300 * 208, 'J'),
      Beat(300 * 209, 'J'),

      Beat(300 * 211, 'J'),
      Beat(300 * 212, 'J'),
      Beat(300 * 213, 'K'),
      Beat(300 * 214, 'K'),

      Beat(300 * 216, 'K'),
      Beat(300 * 217, 'K'),
      Beat(300 * 218, 'I'),
      Beat(300 * 219, 'I'),

      Beat(300 * 221, 'I'),
      Beat(300 * 222, 'I'),
      Beat(300 * 223, 'L'),
      Beat(300 * 224, 'L'),

      Beat(300 * 226, 'K'),
      Beat(300 * 227, 'K'),
      Beat(300 * 228, 'K'),
      Beat(300 * 229, 'K'),

      Beat(300 * 231, 'J'),
      Beat(300 * 232, 'J'),
      Beat(300 * 233, 'J'),
      Beat(300 * 234, 'J'),

      Beat(300 * 235, 'K'),
      Beat(300 * 236, 'K'),
      Beat(300 * 237, 'K'),
      Beat(300 * 238, 'K'),

      Beat(300 * 240, 'J'),
      Beat(300 * 241, 'J'),
      Beat(300 * 242, 'J'),
      Beat(300 * 243, 'J'),

      Beat(300 * 245, 'K'),
      Beat(300 * 247, 'K'),
      Beat(300 * 248, 'K'),
      Beat(300 * 249, 'K'),

      Beat(300 * 251, 'I'),
      Beat(300 * 252, 'I'),
      Beat(300 * 253, 'I'),
      Beat(300 * 254, 'I'),

      Beat(300 * 256, 'L'),
      Beat(300 * 257, 'L'),
      Beat(300 * 258, 'L'),
      Beat(300 * 259, 'L'),

      Beat(300 * 260, 'J'),
      Beat(300 * 262, 'J'),
      Beat(300 * 263, 'J'),
      Beat(300 * 264, 'J'),

      Beat(300 * 266, 'K'),
      Beat(300 * 267, 'K'),
      Beat(300 * 268, 'K'),
      Beat(300 * 269, 'K'),

      Beat(300 * 271, 'K'),
      Beat(300 * 272, 'K'),
      Beat(300 * 273, 'I'),
      Beat(300 * 274, 'I'),

      Beat(300 * 276, 'I'),
      Beat(300 * 277, 'I'),
      Beat(300 * 278, 'L'),
      Beat(300 * 279, 'L'),

      Beat(300 * 281, 'L'),
      Beat(300 * 282, 'L'),
      Beat(300 * 283, 'J'),
      Beat(300 * 284, 'J'),

      Beat(300 * 286, 'J'),
      Beat(300 * 287, 'J'),
      Beat(300 * 288, 'K'),
      Beat(300 * 289, 'K'),

      Beat(300 * 291, 'K'),
      Beat(300 * 292, 'K'),
      Beat(300 * 293, 'I'),
      Beat(300 * 294, 'I'),

      Beat(300 * 296, 'I'),
      Beat(300 * 297, 'I'),
      Beat(300 * 298, 'L'),
      Beat(300 * 299, 'L'),

      Beat(300 * 301, 'L'),
      Beat(300 * 302, 'L'),
      Beat(300 * 303, 'L'),
      Beat(300 * 304, 'L'),

      Beat(300 * 306, 'L'),
      Beat(300 * 307, 'L'),
      Beat(300 * 308, 'J'),
      Beat(300 * 309, 'J'),

      Beat(300 * 311, 'J'),
      Beat(300 * 312, 'J'),
      Beat(300 * 314, 'K'),
      Beat(300 * 314, 'K'),

      Beat(300 * 316, 'K'),
      Beat(300 * 317, 'K'),
      Beat(300 * 318, 'I'),
      Beat(300 * 319, 'I'),

      Beat(300 * 321, 'I'),
      Beat(300 * 322, 'I'),
      Beat(300 * 323, 'L'),
      Beat(300 * 324, 'L'),

      Beat(300 * 326, 'I'),
      Beat(300 * 327, 'I'),
      Beat(300 * 328, 'I'),
      Beat(300 * 329, 'I'),

      Beat(300 * 330, 'I'),
      Beat(300 * 331, 'I'),
      Beat(300 * 332, 'I'),
      Beat(300 * 333, 'I'),

      Beat(300 * 335, 'K'),
      Beat(300 * 336, 'K'),
      Beat(300 * 337, 'K'),
      Beat(300 * 338, 'K'),

      Beat(300 * 340, 'J'),
      Beat(300 * 341, 'J'),
      Beat(300 * 342, 'J'),
      Beat(300 * 343, 'J'),

      Beat(300 * 345, 'K'),
      Beat(300 * 347, 'K'),
      Beat(300 * 348, 'K'),
      Beat(300 * 349, 'K'),

      Beat(300 * 351, 'I'),
      Beat(300 * 352, 'I'),
      Beat(300 * 353, 'I'),
      Beat(300 * 354, 'I'),

      Beat(300 * 356, 'L'),
      Beat(300 * 357, 'L'),
      Beat(300 * 358, 'L'),
      Beat(300 * 359, 'L'),

      Beat(300 * 360, 'J'),
      Beat(300 * 362, 'J'),
      Beat(300 * 363, 'J'),
      Beat(300 * 364, 'J'),

      Beat(300 * 366, 'K'),
      Beat(300 * 367, 'K'),
      Beat(300 * 368, 'K'),
      Beat(300 * 369, 'K'),

      Beat(300 * 371, 'K'),
      Beat(300 * 372, 'K'),
      Beat(300 * 373, 'I'),
      Beat(300 * 374, 'I'),

      Beat(300 * 376, 'I'),
      Beat(300 * 377, 'I'),
      Beat(300 * 378, 'L'),
      Beat(300 * 379, 'L'),

      Beat(300 * 381, 'L'),
      Beat(300 * 382, 'L'),
      Beat(300 * 383, 'J'),
      Beat(300 * 384, 'J'),

      Beat(300 * 386, 'I'),

        //117000 300*390

	};

public:
	Game(int width, int height);

	// 인트로 화면
	void startGame(); //게임창 띄우기
	void controlPage(); //화면전환

	// 게임 화면
	void runGame(int level); //게임 시작
	void drawGame(int level); //게임에 필요한 것들 그려주기
	void dropNotes(int level); //올라올 화살표 배열에 데이터값 넣어주기
	void catchNotes();
	void judge(MovingNote iter); //타이밍 판정

	int textPrint(Text& textMsg, Font& font, int size,
		float x, float y, const Color& color, string p); //텍스트 그려주기

	// 엔딩 화면
	void endPage();
};
#endif