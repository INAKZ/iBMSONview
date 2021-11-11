#pragma once
#include "../util/util.h"
#include "BGAEvent.h"

class DynamicArray_BGAEvent {
public:
	DynamicArray_BGAEvent();
	DynamicArray_BGAEvent(int setsize);
	~DynamicArray_BGAEvent();

	void Zeros();

	int GetSize();
	BGAEvent GetValuen(int n);
	BGAEvent* GetValue();

	void SetSize(int n);
	void SetValue(int n, BGAEvent v);
	void SetValues(BGAEvent* array, int arraysize);

	void InsValues(int n, BGAEvent* v, int vsize);
	void InsValue(int n, BGAEvent v);
	void AddValues(BGAEvent* v, int vsize);
	void AddValue(BGAEvent v);
	void Cat(DynamicArray_BGAEvent *src);
	void DelValue(int n);

private:
	int size;
	BGAEvent* value;
};
typedef DynamicArray_BGAEvent* DA_BGAEvent;