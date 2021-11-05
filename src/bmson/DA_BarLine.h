#pragma once
#include "../util/util.h"
#include "BarLine.h"

class DA_BarLine {
public:
	DA_BarLine();
	DA_BarLine(int setsize);
	~DA_BarLine();

	void Zeros();

	int GetSize();
	BarLine GetValuen(int n);
	BarLine* GetValue();

	void SetValue(int n, BarLine v);
	void SetValues(BarLine* array, int arraysize);

	void InsValues(int n, BarLine* v, int vsize);
	void InsValue(int n, BarLine v);
	void AddValues(BarLine* v, int vsize);
	void AddValue(BarLine v);
	void Cat(DA_BarLine* src);
	void DelValue(int n);

private:
	int size;
	BarLine* value;
};