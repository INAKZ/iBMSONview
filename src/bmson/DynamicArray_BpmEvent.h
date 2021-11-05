#pragma once
#include "../util/util.h"
#include "BpmEvent.h"

class DynamicArray_BpmEvent {
public:
	DynamicArray_BpmEvent();
	DynamicArray_BpmEvent(int setsize);
	~DynamicArray_BpmEvent();

	void Zeros();

	int GetSize();
	BpmEvent GetValuen(int n);
	BpmEvent* GetValue();

	void SetValue(int n, BpmEvent v);
	void SetValues(BpmEvent* array, int arraysize);

	void InsValues(int n, BpmEvent* v, int vsize);
	void InsValue(int n, BpmEvent v);
	void AddValues(BpmEvent* v, int vsize);
	void AddValue(BpmEvent v);
	void Cat(DynamicArray_BpmEvent *src);
	void DelValue(int n);

private:
	int size;
	BpmEvent* value;
};
typedef DynamicArray_BpmEvent* DA_BpmEvent;