#pragma once
#include "../ArrayUtil.h"

class DynamicArrayLongLongInt {
public:
	DynamicArrayLongLongInt();
	DynamicArrayLongLongInt(int setsize);
	~DynamicArrayLongLongInt();

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
	void Cat(DynamicArrayLongLongInt *src);
	void DelValue(int n);

private:
	int size;
	long long int *value;
};
typedef DynamicArrayLongLongInt DynamicArrayLongLong;
typedef DynamicArrayLongLongInt DynamicArrayLLong;
typedef DynamicArrayLongLongInt* DALongLongInt;
typedef DynamicArrayLongLongInt* DALongLong;
typedef DynamicArrayLongLongInt* DALLong;