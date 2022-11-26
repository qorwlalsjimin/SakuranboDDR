#ifndef GAME_FIXEDNODE__H__
#define GAME_FIXEDNODE__H__

#include <SFML/Graphics.hpp>

using namespace sf;

//TODO: RectangleShape로 바꾸기
class FixedNode : public RectangleShape {
private:
	float fixed_nodeX, fixed_nodeY;

public:
	FixedNode();
	FixedNode(Texture* tFixedNode, int& WINDOW_WIDTH, int& WINDOW_HEIGHT);

	void update(float x, float y);
	float getFixedNodeX();
	float getFixedNodeY();
};

#endif // !GAME_FIXEDNODE__H__