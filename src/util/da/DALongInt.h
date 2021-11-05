#pragma once
#include "../ArrayUtil.h"

class DALongInt {
public:
	DALongInt();
	DALongInt(int setsize);
	~DALongInt();

	void Zeros();

	int GetSize();
	long int GetValuen(int n);
	long int *GetValue();

	void SetValue(int n, long int v);
	void SetValues(long int *array, int arraysize);

	void InsValues(int n, long int *v, int vsize);
	void InsValue(int n, long int v);
	void AddValues(long int *v, int vsize);
	void AddValue(long int v);
	void Cat(DALongInt *src);
	void DelValue(int n);

private:
	int size;
	long int *value;
};
typedef DALongInt DALong;