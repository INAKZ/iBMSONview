#pragma once
#include "../ArrayUtil.h"

class DAUnsignedLongInt {
public:
	DAUnsignedLongInt();
	DAUnsignedLongInt(int setsize);
	~DAUnsignedLongInt();

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
	void Cat(DAUnsignedLongInt *src);
	void DelValue(int n);

private:
	int size;
	unsigned long int *value;
};
typedef DAUnsignedLongInt DAUnsignedLong;
typedef DAUnsignedLongInt DAULongInt;
typedef DAUnsignedLongInt DAULong;