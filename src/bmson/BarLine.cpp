#include "BarLine.h"

BarLine::BarLine() {
	y = 0;
}

unsigned long BarLine::GetY() {
	return y;
}

void BarLine::SetY(unsigned long value) {
	y = value;
}