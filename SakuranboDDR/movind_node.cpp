#include "moving_node.h"
#include <string>

using namespace std;

MovingNode::MovingNode() {
}

MovingNode::MovingNode(Texture* tMovingNode, float x, float y, float r) : RectangleShape(sf::Vector2f(100.0f, 100.0f)) {
	moving_nodeX = x;
	moving_nodeY = y;
	setPosition(moving_nodeX, moving_nodeY);
	setRotation(r);
	setTexture(tMovingNode);
}

//TODO: �ڵ����� �����̵���! game.cpp
void MovingNode::update(float y) {
	move(0, y);
	moving_nodeY += y;
}

float MovingNode::getMovingNodeX() {
	return moving_nodeX;
}

float MovingNode::getMovingNodeY() {
	return moving_nodeY;
}