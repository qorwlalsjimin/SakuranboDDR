/*
*	Copyright (C) 2020 by Hannah Noh
*
*	본 헤더파일은 fixed_node 객체를 선언한다.
*
*	Last Updated On 2020.05.29. FRI
*	@author : Hannah Noh
*/

#ifndef GAME_PLAYER__H__
#define GAME_PLAYER__H__

#include <SFML/Graphics.hpp>

using namespace sf;

class FixedNode : public CircleShape {
private:
	float fixed_nodeX, fixed_nodeY;

public:
	FixedNode();
	FixedNode(Texture* tPlayer, int& WINDOW_WIDTH, int& WINDOW_HEIGHT);

	void update(float x, float y);
	float getPlayerX();
	float getPlayerY();
	void setPositionCenter(int& WINDOW_WIDTH, int& WINDOW_HEIGHT);
	void isBite(Texture* tPlayer, int& numofBite);
};

#endif // !GAME_PLAYER__H__