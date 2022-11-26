#include "moving_node.h"
#include <string>

using namespace std;

MovingNode::MovingNode() {
}

MovingNode::MovingNode(Texture* tMovingNode, float x, float y, float r) : RectangleShape(sf::Vector2f(100.0f, 100.0f)) {
	setPosition(x, y);
	setRotation(r);
	setTexture(tMovingNode);
	setFillColor(sf::Color::Blue); //임시
}

//TODO: 자동으로 움직이도록! game.cpp
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