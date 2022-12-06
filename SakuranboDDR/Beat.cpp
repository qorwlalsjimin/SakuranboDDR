#include "Beat.h"

Beat::Beat(int time, string noteName) {
	this->time = time;
	this->noteName = noteName;
}

int Beat::getTime() {
	return time;
}
void Beat::setTime(int time) {
	this->time = time;
}

string Beat::getNoteName() {
	return noteName;
}
void Beat::setNoteName(string noteName) {
	this->noteName = noteName;
}