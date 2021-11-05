#pragma once
#include "../util/util.h"
#include "BGAHeader.h"

class DynamicArray_BGAHeader {
public:
	DynamicArray_BGAHeader();
	DynamicArray_BGAHeader(int setsize);
	~DynamicArray_BGAHeader();

	void Zeros();

	int GetSize();
	BGAHeader GetValuen(int n);
	BGAHeader *GetValue();

	void SetValue(int n, BGAHeader v);
	void SetValues(BGAHeader *array, int arraysize);

	void InsValues(int n, BGAHeader *v, int vsize);
	void InsValue(int n, BGAHeader v);
	void AddValues(BGAHeader *v, int vsize);
	void AddValue(BGAHeader v);
	void Cat(DynamicArray_BGAHeader *src);
	void DelValue(int n);

private:
	int size;
	BGAHeader *value;
};
typedef DynamicArray_BGAHeader* DA_BGAHeader;