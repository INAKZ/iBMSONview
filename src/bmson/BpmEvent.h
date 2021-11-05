#pragma once
#include "../util/util.h"

class BpmEvent{
public:
	BpmEvent();

	unsigned long GetY();
	double GetBpm();

	void SetY(unsigned long value);
	void SetBpm(double value);

private:
	unsigned long y;
	double bpm;
};

