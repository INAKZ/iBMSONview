#pragma once
#include "../ArrayUtil.h"

class DALongLongInt {
public:
	DALongLongInt();
	DALongLongInt(int setsize);
	~DALongLongInt();

	void Zeros();

	int GetSize();
	long long int GetValuen(int n);
	long long int *GetValue();

	void SetValue(int n, long long int v);
	void SetValues(long long int *array, int arraysize);

	void InsValues(int n, long long int *v, int vsize);
	void InsValue(int n, long long int v);
	void AddValues(long long int *v, int vsize);
	void AddValue(long long int v);
	void Cat(DALongLongInt *src);
	void DelValue(int n);

private:
	int size;
	long long int *value;
};