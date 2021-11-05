#pragma once
#include "../util/util.h"
#include "BpmEvent.h"

class DA_BpmEvent {
public:
	DA_BpmEvent();
	DA_BpmEvent(int setsize);
	~DA_BpmEvent();

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
	void Cat(DA_BpmEvent* src);
	void DelValue(int n);

private:
	int size;
	BpmEvent* value;
};