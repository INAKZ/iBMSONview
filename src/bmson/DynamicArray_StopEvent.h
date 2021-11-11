#pragma once
#include "../util/util.h"
#include "StopEvent.h"

class DynamicArray_StopEvent {
public:
	DynamicArray_StopEvent();
	DynamicArray_StopEvent(int setsize);
	~DynamicArray_StopEvent();

	void Zeros();

	int GetSize();
	StopEvent GetValuen(int n);
	StopEvent* GetValue();

	void SetSize(int n);
	void SetValue(int n, StopEvent v);
	void SetValues(StopEvent* array, int arraysize);

	void InsValues(int n, StopEvent* v, int vsize);
	void InsValue(int n, StopEvent v);
	void AddValues(StopEvent* v, int vsize);
	void AddValue(StopEvent v);
	void Cat(DynamicArray_StopEvent *src);
	void DelValue(int n);

private:
	int size;
	StopEvent* value;
};
typedef DynamicArray_StopEvent* DA_StopEvent;