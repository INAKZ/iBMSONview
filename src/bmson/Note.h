#pragma once
#include "../util/util.h"

class Note{
public:
	Note();

	void Zeros();

	int GetX();
	unsigned long GetY();
	unsigned long GetL();
	boolean GetC();

	void SetX(int value);
	void SetY(unsigned long value);
	void SetL(unsigned long value);
	void SetC(boolean value);

private:
	int x;
	unsigned long y;
	unsigned long l;
	boolean c;
};

