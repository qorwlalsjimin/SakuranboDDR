#pragma once

// ������� �ߺ� ����
#ifndef BEAT_H_
#define BEAT_H_


class Beat {
private:
	int time;
	char noteName;
public:
	Beat();
	Beat(int time, char noteName);

	int getTime();
	void setTime(int time);

	char getNoteName();
	void setNoteName(char noteName);
};

#endif