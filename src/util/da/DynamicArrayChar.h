#pragma once
#include "../ArrayUtil.h"


class DynamicArrayChar{
public:
	DynamicArrayChar();
	DynamicArrayChar(int setsize);
	DynamicArrayChar(char* setvalue);
	DynamicArrayChar(int setsize, char* setvalue);
	~DynamicArrayChar();

	void Zeros();
	void UpdateSize();

	int GetSize();
	char GetValuen(int n);
	char *GetValue();

	void SetSize(int n);
	void SetValue(int n, char v);
	void SetValues(char *array, int arraysize);

	void InsValues(int n, char *v, int vsize);
	void InsValue(int n, char v);
	void AddValues(char *v, int vsize);
	void AddValue(char v);
	void Cat(DynamicArrayChar *src);
	void DelValue(int n);

private:
	int size;
	char *value;
};
//typedef DynamicArrayChar _String;
typedef DynamicArrayChar* DAChar;
typedef DynamicArrayChar* String;