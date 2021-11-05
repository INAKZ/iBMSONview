#pragma once
#include "../ArrayUtil.h"

class DAUnsignedInt {
public:
	DAUnsignedInt();
	DAUnsignedInt(int setsize);
	~DAUnsignedInt();

	void Zeros();

	int GetSize();
	unsigned int GetValuen(int n);
	unsigned int *GetValue();

	void SetValue(int n, unsigned int v);
	void SetValues(unsigned int *array, int arraysize);

	void InsValues(int n, unsigned int *v, int vsize);
	void InsValue(int n, unsigned int v);
	void AddValues(unsigned int *v, int vsize);
	void AddValue(unsigned int v);
	void Cat(DAUnsignedInt *src);
	void DelValue(int n);

private:
	int size;
	unsigned int *value;
};
typedef DAUnsignedInt DAUnsigned;
typedef DAUnsignedInt DAUInt;