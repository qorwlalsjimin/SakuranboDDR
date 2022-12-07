#ifndef GAME_MOVINGNOTE__H__
#define GAME_MOVINGNOTE__H__

#include <SFML/Graphics.hpp>

using namespace sf;

class MovingNote : public RectangleShape {
private:

public:
	float moving_nodeX, moving_nodeY;
	char arrow;

	MovingNote();
	MovingNote(Texture* tMovingNote, char arrow);
	MovingNote(Texture* tMovingNote, int& WINDOW_WIDTH, int& WINDOW_HEIGHT);

	void update(float y);

	float getMovingNoteX();
	float getMovingNoteY();
	char getArrow();
};

#endif // !GAME_MOVINGNOTE__H__