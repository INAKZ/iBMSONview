#pragma once
#include "../ArrayUtil.h"

class DAUnsignedLongLongInt {
public:
	DAUnsignedLongLongInt();
	DAUnsignedLongLongInt(int setsize);
	~DAUnsignedLongLongInt();

	void Zeros();

	int GetSize();
	unsigned long long int GetValuen(int n);
	unsigned long long int *GetValue();

	void SetValue(int n, unsigned long long int v);
	void SetValues(unsigned long long int *array, int arraysize);

	void InsValues(int n, unsigned long long int *v, int vsize);
	void InsValue(int n, unsigned long long int v);
	void AddValues(unsigned long long int *v, int vsize);
	void AddValue(unsigned long long int v);
	void Cat(DAUnsignedLongLongInt *src);
	void DelValue(int n);

private:
	int size;
	unsigned long long int *value;
};
typedef DAUnsignedLongLongInt DAUnsignedLongLong;
typedef DAUnsignedLongLongInt DAULongLongInt;
typedef DAUnsignedLongLongInt DAULongLong;