#include "Beat.h"

Beat::Beat(){}

Beat::Beat(int time, char noteName) {
	this->time = time;
	this->noteName = noteName;
}

int Beat::getTime() {
	return time;
}
void Beat::setTime(int time) {
	this->time = time;
}

char Beat::getNoteName() {
	return noteName;
}
void Beat::setNoteName(char noteName) {
	this->noteName = noteName;
}