#pragma once
#include "../ArrayUtil.h"

class DADouble {
public:
	DADouble();
	DADouble(int setsize);
	~DADouble();

	void Zeros();

	int GetSize();
	double GetValuen(int n);
	double *GetValue();

	void SetValue(int n, double v);
	void SetValues(double *array, int arraysize);

	void InsValues(int n, double *v, int vsize);
	void InsValue(int n, double v);
	void AddValues(double *v, int vsize);
	void AddValue(double v);
	void Cat(DADouble *src);
	void DelValue(int n);

private:
	int size;
	double *value;
};