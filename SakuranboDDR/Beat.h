#pragma once

// 헤더파일 중복 방지
#ifndef BEAT_H_
#define BEAT_H_

#include <string>
using namespace std;

class Beat {
private:
	int time;
	string noteName;
public:
	Beat(int time, string noteName) {};

	int getTime();
	void setTime(int time);

	string getNoteName();
	void setNoteName(string noteName);
};

#endif