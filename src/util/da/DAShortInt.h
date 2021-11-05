#pragma once
#include "../ArrayUtil.h"

class DAShortInt {
public:
	DAShortInt();
	DAShortInt(int setsize);
	~DAShortInt();

	void Zeros();

	int GetSize();
	short int GetValuen(int n);
	short int* GetValue();

	void SetValue(int n, short int v);
	void SetValues(short int* array, int arraysize);

	void InsValues(int n, short int* v, int vsize);
	void InsValue(int n, short int v);
	void AddValues(short int* v, int vsize);
	void AddValue(short int v);
	void Cat(DAShortInt* src);
	void DelValue(int n);

private:
	int size;
	short int* value;
};
typedef DAShortInt DAShort;