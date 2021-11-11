#include "DynamicArrayShortInt.h"

DynamicArrayShortInt::DynamicArrayShortInt() {
	size = 1;
	value = new short int[size];
	value[0] = 0;
}
DynamicArrayShortInt::DynamicArrayShortInt(int setsize) {
	size = setsize;
	value = new short int[size];
	ZerosShortInt(value, size);
}
DynamicArrayShortInt::~DynamicArrayShortInt() {
	delete[] value;
}

void DynamicArrayShortInt::Zeros() {
	ZerosShortInt(value, size);
}

int DynamicArrayShortInt::GetSize() {
	return size;
}
short int DynamicArrayShortInt::GetValuen(int n) {
	return value[n];
}
short int* DynamicArrayShortInt::GetValue() {
	return value;
}

void DynamicArrayShortInt::SetValue(int n, short int v) {
	if (n > size) { return; }
	value[n] = v;
}
void DynamicArrayShortInt::SetValues(short int* array, int arraysize) {
	short int* tmp;
	tmp = new short int[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete[] value;
	value = tmp;
	size = arraysize;
}

void DynamicArrayShortInt::InsValues(int n, short int* v, int vsize) {
	short int* tmp;
	if (n > size) { return; }
	tmp = new short int[size + vsize];
	for (int i = 0; i < n; i++) {
		tmp[i] = value[i];
	}
	for (int i = n; i < n + vsize; i++) {
		tmp[i] = v[i - n];
	}
	for (int i = n + vsize; i < size + vsize; i++) {
		tmp[i] = value[i - vsize];
	}
	delete[] value;
	value = tmp;
	size += vsize;
}
void DynamicArrayShortInt::InsValue(int n, short int v) {
	InsValues(n, &v, 1);
}
void DynamicArrayShortInt::AddValues(short int* v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArrayShortInt::AddValue(short int v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArrayShortInt::Cat(DynamicArrayShortInt *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArrayShortInt::DelValue(int n) {
	if (n >= size) { return; }
	short int* tmp;
	tmp = new short int[size - 1];
	for (int i = 0; i < n; i++) {
		tmp[i] = value[i];
	}
	for (int i = n + 1; i < size; i++) {
		tmp[i - 1] = value[i];
	}
	delete[] value;
	value = tmp;
	size--;
}
