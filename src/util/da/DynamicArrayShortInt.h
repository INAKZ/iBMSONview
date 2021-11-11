#pragma once
#include "../ArrayUtil.h"

class DynamicArrayShortInt {
public:
	DynamicArrayShortInt();
	DynamicArrayShortInt(int setsize);
	~DynamicArrayShortInt();

	void Zeros();

	int GetSize();
	short int GetValuen(int n);
	short int* GetValue();

	void SetSize(int n);
	void SetValue(int n, short int v);
	void SetValues(short int* array, int arraysize);

	void InsValues(int n, short int* v, int vsize);
	void InsValue(int n, short int v);
	void AddValues(short int* v, int vsize);
	void AddValue(short int v);
	void Cat(DynamicArrayShortInt *src);
	void DelValue(int n);

private:
	int size;
	short int* value;
};
typedef DynamicArrayShortInt DynamicArrayShort;
typedef DynamicArrayShortInt* DAShortInt;
typedef DynamicArrayShortInt* DAShort;