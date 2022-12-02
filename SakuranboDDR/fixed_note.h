#ifndef GAME_FIXEDNODE__H__
#define GAME_FIXEDNODE__H__

#include <SFML/Graphics.hpp>

using namespace sf;

class FixedNote : public RectangleShape {
private:
	float fixed_noteX, fixed_noteY;

public:
	FixedNote();
	FixedNote(Texture* tFixedNote, int& WINDOW_WIDTH, int& WINDOW_HEIGHT);

	void update(float x, float y);
	float getFixedNoteX();
	float getFixedNoteY();
};

#endif // !GAME_FIXEDNODE__H__