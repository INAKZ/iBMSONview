#pragma once
#include "../util/util.h"

class StopEvent {
public:
	StopEvent();

	unsigned long GetY();
	unsigned long GetDuration();

	void SetY(unsigned long value);
	void SetDuration(unsigned long value);

private:
	unsigned long y;
	unsigned long duration;
};

