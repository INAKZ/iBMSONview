#pragma once
#include "../util/util.h"

class BarLine {
public:
	BarLine();

	unsigned long GetY();

	void SetY(unsigned long value);

private:
	unsigned long y;
};