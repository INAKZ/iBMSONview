#pragma once
#include "../ArrayUtil.h"

class DynamicArrayUnsignedLongLongInt {
public:
	DynamicArrayUnsignedLongLongInt();
	DynamicArrayUnsignedLongLongInt(int setsize);
	~DynamicArrayUnsignedLongLongInt();

	void Zeros();

	int GetSize();
	unsigned long long int GetValuen(int n);
	unsigned long long int *GetValue();

	void SetSize(int n);
	void SetValue(int n, unsigned long long int v);
	void SetValues(unsigned long long int *array, int arraysize);

	void InsValues(int n, unsigned long long int *v, int vsize);
	void InsValue(int n, unsigned long long int v);
	void AddValues(unsigned long long int *v, int vsize);
	void AddValue(unsigned long long int v);
	void Cat(DynamicArrayUnsignedLongLongInt *src);
	void DelValue(int n);

private:
	int size;
	unsigned long long int *value;
};
typedef DynamicArrayUnsignedLongLongInt DynamicArrayUnsignedLongLong;
typedef DynamicArrayUnsignedLongLongInt DynamicArrayULongLongInt;
typedef DynamicArrayUnsignedLongLongInt DynamicArrayULongLong;
typedef DynamicArrayUnsignedLongLongInt DynamicArrayULLong;
typedef DynamicArrayUnsignedLongLongInt* DAUnsignedLongLongInt;
typedef DynamicArrayUnsignedLongLongInt* DAUnsignedLongLong;
typedef DynamicArrayUnsignedLongLongInt* DAULongLongInt;
typedef DynamicArrayUnsignedLongLongInt* DAULongLong;
typedef DynamicArrayUnsignedLongLongInt* DAULLong;