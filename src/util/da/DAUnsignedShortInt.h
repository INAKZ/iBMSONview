#pragma once
#include "../ArrayUtil.h"

class DAUnsignedShortInt {
public:
	DAUnsignedShortInt();
	DAUnsignedShortInt(int setsize);
	~DAUnsignedShortInt();

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
	void Cat(DAUnsignedShortInt *src);
	void DelValue(int n);

private:
	int size;
	unsigned short int *value;
};
typedef DAUnsignedShortInt DAUnsignedShort;
typedef DAUnsignedShortInt DAUShortInt;
typedef DAUnsignedShortInt DAUShort;