#pragma once
#include "../util/util.h"
#include "BGAEvent.h"

class DA_BGAEvent {
public:
	DA_BGAEvent();
	DA_BGAEvent(int setsize);
	~DA_BGAEvent();

	void Zeros();

	int GetSize();
	BGAEvent GetValuen(int n);
	BGAEvent* GetValue();

	void SetValue(int n, BGAEvent v);
	void SetValues(BGAEvent* array, int arraysize);

	void InsValues(int n, BGAEvent* v, int vsize);
	void InsValue(int n, BGAEvent v);
	void AddValues(BGAEvent* v, int vsize);
	void AddValue(BGAEvent v);
	void Cat(DA_BGAEvent* src);
	void DelValue(int n);

private:
	int size;
	BGAEvent* value;
};