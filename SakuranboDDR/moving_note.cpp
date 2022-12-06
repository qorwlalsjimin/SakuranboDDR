#include "moving_note.h"
#include <string>

using namespace std;

MovingNote::MovingNote() {
}

MovingNote::MovingNote(Texture* tMovingNode, char arrow) : RectangleShape(sf::Vector2f(100.0f, 100.0f)) {

	//x좌표 화살표에 따라 위치 설정
	switch (arrow) {
		case 'L':
			moving_nodeX = 220.f; //x좌표
			setRotation(0.f);  //이미지 회전 (화살표 이미지가 <-로 하나밖에 없기 때문)
			break;
		case 'U':
			moving_nodeX = 342.f;
			setRotation(90.f);  //이미지 회전 (화살표 이미지가 <-로 하나밖에 없기 때문)
			break;
		case 'R':
			moving_nodeX = 586.f;
			setRotation(180.f);  //이미지 회전 (화살표 이미지가 <-로 하나밖에 없기 때문)
			break;
		case 'D':
			moving_nodeX = 464.f;
			setRotation(270.f);  //이미지 회전 (화살표 이미지가 <-로 하나밖에 없기 때문)
			break;
	}

	moving_nodeY = 800.f;
	setOrigin(50, 50); //회전 전에 중심점 잡아주기
	setPosition(moving_nodeX, moving_nodeY); //객체 위치 잡아주기
	setTexture(tMovingNode);
}

void MovingNote::update(float y) {
	move(0, y);
	moving_nodeY += y; //위로 올라감
}

//x좌표 얻기
float MovingNote::getMovingNoteX() {
	return moving_nodeX; 
}

//y좌표 얻기
float MovingNote::getMovingNoteY() {
	return moving_nodeY;
}