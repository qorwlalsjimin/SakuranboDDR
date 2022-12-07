#include "moving_note.h"
#include <string>

using namespace std;

MovingNote::MovingNote() {
}

MovingNote::MovingNote(Texture* tMovingNode, char arrow) : RectangleShape(sf::Vector2f(100.0f, 100.0f)) {
	this->arrow = arrow;

	//x��ǥ ȭ��ǥ�� ���� ��ġ ����
	switch (arrow) {
		case 'J':
			moving_nodeX = 220.f; //x��ǥ
			setRotation(0.f);  //�̹��� ȸ�� (ȭ��ǥ �̹����� <-�� �ϳ��ۿ� ���� ����)
			break;
		case 'K':
			moving_nodeX = 342.f;
			setRotation(270.f);  //�̹��� ȸ�� (ȭ��ǥ �̹����� <-�� �ϳ��ۿ� ���� ����)
			break;
		case 'I':
			moving_nodeX = 464.f;
			setRotation(90.f);  //�̹��� ȸ�� (ȭ��ǥ �̹����� <-�� �ϳ��ۿ� ���� ����)
			break;
		case 'L':
			moving_nodeX = 586.f;
			setRotation(180.f);  //�̹��� ȸ�� (ȭ��ǥ �̹����� <-�� �ϳ��ۿ� ���� ����)
			break;
	}

	moving_nodeY = 800.f;
	setOrigin(50, 50); //ȸ�� ���� �߽��� ����ֱ�
	setPosition(moving_nodeX, moving_nodeY); //��ü ��ġ ����ֱ�
	setTexture(tMovingNode);
}


void MovingNote::update(float y) {
	move(0, y);
	moving_nodeY += y; //���� �ö�
}

//x��ǥ ���
float MovingNote::getMovingNoteX() {
	return moving_nodeX; 
}

//y��ǥ ���
float MovingNote::getMovingNoteY() {
	return moving_nodeY;
}

char MovingNote::getArrow() {
	return arrow;
}