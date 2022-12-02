#include "moving_node.h"
#include <string>

using namespace std;

MovingNode::MovingNode() {
}

MovingNode::MovingNode(Texture* tMovingNode, float x, float y, float r) : RectangleShape(sf::Vector2f(100.0f, 100.0f)) {
	moving_nodeX = x; //생성될 x좌표 위치 설정
	moving_nodeY = y; //생성될 y좌표 위치 설정
	setPosition(moving_nodeX, moving_nodeY); //객체 위치 잡아주기
	setOrigin(50, 50); //회전 전에 중심점 잡아주기
	setRotation(r);  //이미지 회전 (화살표 이미지가 <-로 하나밖에 없기 때문)
	setTexture(tMovingNode);
}

void MovingNode::update(float y) {
	move(0, y);
	moving_nodeY += y; //위로 올라감
}

//x좌표 얻기
float MovingNode::getMovingNodeX() {
	return moving_nodeX; 
}

//y좌표 얻기
float MovingNode::getMovingNodeY() {
	return moving_nodeY;
}