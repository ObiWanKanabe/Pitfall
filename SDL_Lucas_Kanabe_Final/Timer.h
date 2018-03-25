#ifndef TIMER_H
#define TIMER_H

#include "SDL.h"

// This timer was what Scott made us use for SDL, if it ain't broke, don't fix it. ¯\_(?)_/¯

class Timer {
private:
	unsigned int prevTicks;
	unsigned int currTicks;
public:
	Timer();
	~Timer();

	void Start();
	void UpdateFrameTicks();
	float GetDeltaTime() const;
	unsigned int GetSleepTime(const unsigned int fps) const;
};

#endif