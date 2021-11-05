#pragma once
#include "../ArrayUtil.h"
#include "DAChar.h"

class DA_DAChar {
public:
	DA_DAChar();
	DA_DAChar(int setsize);
	~DA_DAChar();

	void Zeros();

	int GetSize();
	DAChar GetValuen(int n);
	DAChar* GetValue();

	void SetValue(int n, DAChar v);
	void SetValues(DAChar* array, int arraysize);

	void InsValues(int n, DAChar* v, int vsize);
	void InsValue(int n, DAChar v);
	void AddValues(DAChar* v, int vsize);
	void AddValue(DAChar v);
	void Cat(DA_DAChar* src);
	void DelValue(int n);

private:
	int size;
	DAChar* value;
};
typedef DA_DAChar* DA_DAString;
typedef DA_DAChar* DA_DString;
typedef DA_DAChar* DDString;
