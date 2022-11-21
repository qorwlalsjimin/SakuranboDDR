/*
*	Copyright (C) 2020 by Hannah Noh
*
*	본 cpp 파일은 fixed_node 객체를 정의한다.
*
*	Last Updated On 2020.05.29. FRI
*	@author : Hannah Noh
*/

#include "fixed_node.h"
#include <string>

using namespace std;

FixedNode::FixedNode() {
}

FixedNode::FixedNode(Texture* tPlayer, int& WINDOW_WIDTH, int& WINDOW_HEIGHT) : CircleShape(50.0) {
	setTexture(tPlayer);
	setPositionCenter(WINDOW_WIDTH, WINDOW_HEIGHT);
	setOrigin(50, 50);
}

void FixedNode::update(float x, float y) {
	move(x, y);
	fixed_nodeX += x;
	fixed_nodeY += y;
}

float FixedNode::getPlayerX() {
	return fixed_nodeX;
}

float FixedNode::getPlayerY() {
	return fixed_nodeY;
}

void FixedNode::setPositionCenter(int& WINDOW_WIDTH, int& WINDOW_HEIGHT) {
	fixed_nodeX = (float)(WINDOW_WIDTH / 2);
	fixed_nodeY = (float)(WINDOW_HEIGHT / 2);
	setPosition(fixed_nodeX, fixed_nodeY);
}

void FixedNode::isBite(Texture* tPlayer, int& numofBite) {
	string fileAddress = "Images/fixed_node_bee" + to_string(numofBite) + ".png";
	tPlayer->loadFromFile(fileAddress);
	setTexture(tPlayer);
}