#pragma once
#include "../ArrayUtil.h"

class DynamicArrayUnsignedInt {
public:
	DynamicArrayUnsignedInt();
	DynamicArrayUnsignedInt(int setsize);
	~DynamicArrayUnsignedInt();

	void Zeros();

	int GetSize();
	unsigned int GetValuen(int n);
	unsigned int *GetValue();

	void SetSize(int n);
	void SetValue(int n, unsigned int v);
	void SetValues(unsigned int *array, int arraysize);

	void InsValues(int n, unsigned int *v, int vsize);
	void InsValue(int n, unsigned int v);
	void AddValues(unsigned int *v, int vsize);
	void AddValue(unsigned int v);
	void Cat(DynamicArrayUnsignedInt *src);
	void DelValue(int n);

private:
	int size;
	unsigned int *value;
};
typedef DynamicArrayUnsignedInt DynamicArrayUnsigned;
typedef DynamicArrayUnsignedInt DynamicArrayUInt;
typedef DynamicArrayUnsignedInt* DAUnsignedInt;
typedef DynamicArrayUnsignedInt* DAUnsigned;
typedef DynamicArrayUnsignedInt* DAUInt;