#pragma once
#include "../util/util.h"
#include "BarLine.h"

class DynamicArray_BarLine {
public:
	DynamicArray_BarLine();
	DynamicArray_BarLine(int setsize);
	~DynamicArray_BarLine();

	void Zeros();

	int GetSize();
	BarLine GetValuen(int n);
	BarLine* GetValue();

	void SetSize(int n);
	void SetValue(int n, BarLine v);
	void SetValues(BarLine* array, int arraysize);

	void InsValues(int n, BarLine* v, int vsize);
	void InsValue(int n, BarLine v);
	void AddValues(BarLine* v, int vsize);
	void AddValue(BarLine v);
	void Cat(DynamicArray_BarLine *src);
	void DelValue(int n);

private:
	int size;
	BarLine* value;
};
typedef DynamicArray_BarLine* DA_BarLine;