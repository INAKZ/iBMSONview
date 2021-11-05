#pragma once
#include "../util/util.h"

class BGAEvent {
public:
	BGAEvent();

	unsigned long GetY();
	unsigned long GetId();

	void SetY(unsigned long value);
	void SetId(unsigned long value);

private:
	unsigned long y;
	unsigned long id;
};