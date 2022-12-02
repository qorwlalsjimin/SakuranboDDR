#ifndef GAME_MOVINGNODE__H__
#define GAME_MOVINGNODE__H__

#include <SFML/Graphics.hpp>

using namespace sf;

class MovingNode : public RectangleShape {
private:

public:
	float moving_nodeX, moving_nodeY;
	MovingNode();
	MovingNode(Texture* tMovingNode, float x, float y, float r);
	MovingNode(Texture* tMovingNode, int& WINDOW_WIDTH, int& WINDOW_HEIGHT);

	void update(float y);
	float getMovingNodeX();
	float getMovingNodeY();
};

#endif // !GAME_MOVINGNODE__H__