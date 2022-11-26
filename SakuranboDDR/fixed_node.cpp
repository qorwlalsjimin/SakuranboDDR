#include "fixed_node.h"
#include <string>

using namespace std;

FixedNode::FixedNode() {
}

FixedNode::FixedNode(Texture* tPlayer, int& WINDOW_WIDTH, int& WINDOW_HEIGHT) : RectangleShape(sf::Vector2f(100.0f,100.0f)) {
	setTexture(tPlayer);
	setOrigin(50, 50);
	setFillColor(sf::Color::White); //юс╫ц
}

void FixedNode::update(float x, float y) {
	move(x, y);
	fixed_nodeX += x;
	fixed_nodeY += y;
}

float FixedNode::getFixedNodeX() {
	return fixed_nodeX;
}

float FixedNode::getFixedNodeY() {
	return fixed_nodeY;
}