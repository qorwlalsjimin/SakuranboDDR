#include "moving_node.h"
#include <string>

using namespace std;

MovingNode::MovingNode() {
}

MovingNode::MovingNode(Texture* tMovingNode, float x, float y, float r) : RectangleShape(sf::Vector2f(100.0f, 100.0f)) {
	moving_nodeX = x; //������ x��ǥ ��ġ ����
	moving_nodeY = y; //������ y��ǥ ��ġ ����
	setPosition(moving_nodeX, moving_nodeY); //��ü ��ġ ����ֱ�
	setOrigin(50, 50); //ȸ�� ���� �߽��� ����ֱ�
	setRotation(r);  //�̹��� ȸ�� (ȭ��ǥ �̹����� <-�� �ϳ��ۿ� ���� ����)
	setTexture(tMovingNode);
}

void MovingNode::update(float y) {
	move(0, y);
	moving_nodeY += y; //���� �ö�
}

//x��ǥ ���
float MovingNode::getMovingNodeX() {
	return moving_nodeX; 
}

//y��ǥ ���
float MovingNode::getMovingNodeY() {
	return moving_nodeY;
}