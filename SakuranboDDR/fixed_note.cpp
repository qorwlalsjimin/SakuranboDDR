#include "fixed_note.h"
#include <string>

using namespace std;

FixedNote::FixedNote() {
}

FixedNote::FixedNote(Texture* tPlayer, int& WINDOW_WIDTH, int& WINDOW_HEIGHT) : RectangleShape(sf::Vector2f(100.0f,100.0f)) {
	setTexture(tPlayer);
	setOrigin(50, 50);
}

void FixedNote::update(float x, float y) {
	move(x, y);
	fixed_noteX += x;
	fixed_noteY += y;
}

float FixedNote::getFixedNoteX() {
	return fixed_noteX;
}

float FixedNote::getFixedNoteY() {
	return fixed_noteY;
}