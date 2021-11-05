#pragma once
#include "../util/util.h"
#include "BGAHeader.h"

class DA_BGAHeader {
public:
	DA_BGAHeader();
	DA_BGAHeader(int setsize);
	~DA_BGAHeader();

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
	void Cat(DA_BGAHeader *src);
	void DelValue(int n);

private:
	int size;
	BGAHeader *value;
};