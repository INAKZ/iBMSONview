#pragma once
#include "../util/util.h"
#include "StopEvent.h"

class DA_StopEvent {
public:
	DA_StopEvent();
	DA_StopEvent(int setsize);
	~DA_StopEvent();

	void Zeros();

	int GetSize();
	StopEvent GetValuen(int n);
	StopEvent* GetValue();

	void SetValue(int n, StopEvent v);
	void SetValues(StopEvent* array, int arraysize);

	void InsValues(int n, StopEvent* v, int vsize);
	void InsValue(int n, StopEvent v);
	void AddValues(StopEvent* v, int vsize);
	void AddValue(StopEvent v);
	void Cat(DA_StopEvent* src);
	void DelValue(int n);

private:
	int size;
	StopEvent* value;
};