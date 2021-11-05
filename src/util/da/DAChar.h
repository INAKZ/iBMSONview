#pragma once
#include "../ArrayUtil.h"


class DAChar {
public:
	DAChar();
	DAChar(int setsize);
	DAChar(int setsize, char* setvalue);
	~DAChar();

	void Zeros();

	int GetSize();
	char GetValuen(int n);
	char *GetValue();

	void SetValue(int n, char v);
	void SetValues(char *array, int arraysize);

	void InsValues(int n, char *v, int vsize);
	void InsValue(int n, char v);
	void AddValues(char *v, int vsize);
	void AddValue(char v);
	void Cat(DAChar *src);
	void DelValue(int n);

private:
	int size;
	char *value;
};
typedef DAChar* DAString;
typedef DAChar* DString;