#pragma once
#include "../ArrayUtil.h"
#include "DynamicArrayChar.h"

class DynamicArray_DAChar {
public:
	DynamicArray_DAChar();
	DynamicArray_DAChar(int setsize);
	~DynamicArray_DAChar();

	void Zeros();

	int GetSize();
	DynamicArrayChar GetValuen(int n);
	DAChar GetValue();

	void SetValue(int n, DynamicArrayChar v);
	void SetValues(DAChar array, int arraysize);

	void InsValues(int n, DAChar v, int vsize);
	void InsValue(int n, DynamicArrayChar v);
	void AddValues(DAChar v, int vsize);
	void AddValue(DynamicArrayChar v);
	void Cat(DynamicArray_DAChar *src);
	void DelValue(int n);

private:
	int size;
	DAChar value;
};
typedef DynamicArray_DAChar* DA_DAChar;
typedef DynamicArray_DAChar* DA_String;
