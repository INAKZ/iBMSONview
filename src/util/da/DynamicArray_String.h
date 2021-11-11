#pragma once
#include "../ArrayUtil.h"
#include "DynamicArrayChar.h"

class DynamicArray_String {
public:
	DynamicArray_String();
	DynamicArray_String(int setsize);
	DynamicArray_String(String setvalue);
	~DynamicArray_String();

	void Zeros();

	int GetSize();
	String GetValuen(int n);
	String *GetValue();

	void SetSize(int n);
	void SetValue(int n, String v);
	void SetValues(String *array, int arraysize);

	void InsValues(int n, String *v, int vsize);
	void InsValue(int n, String v);
	void AddValues(String *v, int vsize);
	void AddValue(String v);
	void Cat(DynamicArray_String *src);
	void DelValue(int n);

private:
	int size;
	String *value;
};
typedef DynamicArray_String* DA_DAChar;
typedef DynamicArray_String* DA_String;
