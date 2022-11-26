#include "moving_node.h"
#include <string>

using namespace std;

MovingNode::MovingNode() {
}

MovingNode::MovingNode(Texture* tMovingNode, int& WINDOW_WIDTH, int& WINDOW_HEIGHT) : RectangleShape(sf::Vector2f(100.0f, 100.0f)) {
	setTexture(tMovingNode);
	setOrigin(50, 50);
	setFillColor(sf::Color::Blue); //�ӽ�
}

//TODO: �ڵ����� �����̵���! game.cpp
void MovingNode::update(float y) {
	move(0, y);
	moving_nodeY -= y;
}

float MovingNode::getMovingNodeX() {
	return moving_nodeX;
}

float MovingNode::getMovingNodeY() {
	return moving_nodeY;
}