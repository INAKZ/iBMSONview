#pragma once
#include "../ArrayUtil.h"

class DynamicArrayUnsignedLongInt {
public:
	DynamicArrayUnsignedLongInt();
	DynamicArrayUnsignedLongInt(int setsize);
	~DynamicArrayUnsignedLongInt();

	void Zeros();

	int GetSize();
	unsigned long int GetValuen(int n);
	unsigned long int *GetValue();

	void SetValue(int n, unsigned long int v);
	void SetValues(unsigned long int *array, int arraysize);

	void InsValues(int n, unsigned long int *v, int vsize);
	void InsValue(int n, unsigned long int v);
	void AddValues(unsigned long int *v, int vsize);
	void AddValue(unsigned long int v);
	void Cat(DynamicArrayUnsignedLongInt *src);
	void DelValue(int n);

private:
	int size;
	unsigned long int *value;
};
typedef DynamicArrayUnsignedLongInt DynamicArrayUnsignedLong;
typedef DynamicArrayUnsignedLongInt DynamicArrayULongInt;
typedef DynamicArrayUnsignedLongInt DynamicArrayULong;
typedef DynamicArrayUnsignedLongInt* DAUnsignedLongInt;
typedef DynamicArrayUnsignedLongInt* DAUnsignedLong;
typedef DynamicArrayUnsignedLongInt* DAULongInt;
typedef DynamicArrayUnsignedLongInt* DAULong;