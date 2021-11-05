#pragma once
#include "../ArrayUtil.h"

class DynamicArrayUnsignedShortInt {
public:
	DynamicArrayUnsignedShortInt();
	DynamicArrayUnsignedShortInt(int setsize);
	~DynamicArrayUnsignedShortInt();

	void Zeros();

	int GetSize();
	unsigned short int GetValuen(int n);
	unsigned short int *GetValue();

	void SetValue(int n, unsigned short int v);
	void SetValues(unsigned short int *array, int arraysize);

	void InsValues(int n, unsigned short int *v, int vsize);
	void InsValue(int n, unsigned short int v);
	void AddValues(unsigned short int *v, int vsize);
	void AddValue(unsigned short int v);
	void Cat(DynamicArrayUnsignedShortInt *src);
	void DelValue(int n);

private:
	int size;
	unsigned short int *value;
};
typedef DynamicArrayUnsignedShortInt DynamicArrayUnsignedShort;
typedef DynamicArrayUnsignedShortInt DynamicArrayUShortInt;
typedef DynamicArrayUnsignedShortInt DynamicArrayUShort;
typedef DynamicArrayUnsignedShortInt* DAUnsignedShortInt;
typedef DynamicArrayUnsignedShortInt* DAUnsignedShort;
typedef DynamicArrayUnsignedShortInt* DAUShortInt;
typedef DynamicArrayUnsignedShortInt* DAUShort;