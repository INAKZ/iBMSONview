#pragma once
#include "../ArrayUtil.h"

class DAInt {
public:
	DAInt();
	DAInt(int setsize);
	~DAInt();

	void Zeros();

	int GetSize();
	int GetValuen(int n);
	int *GetValue();

	void SetValue(int n, int v);
	void SetValues(int *array, int arraysize);

	void InsValues(int n, int *v, int vsize);
	void InsValue(int n, int v);
	void AddValues(int *v, int vsize);
	void AddValue(int v);
	void Cat(DAInt *src);
	void DelValue(int n);

private:
	int size;
	int *value;
};