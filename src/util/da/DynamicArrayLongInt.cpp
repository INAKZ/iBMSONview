#include "DynamicArrayLongInt.h"

DynamicArrayLongInt::DynamicArrayLongInt() {
	size = 1;
	value = new long int[size];
	value[0] = 0;
}
DynamicArrayLongInt::DynamicArrayLongInt(int setsize) {
	size = setsize;
	value = new long int[size];
	ZerosLongInt(value, size);
}
DynamicArrayLongInt::~DynamicArrayLongInt() {
	delete value;
}

void DynamicArrayLongInt::Zeros() {
	ZerosLongInt(value, size);
}

int DynamicArrayLongInt::GetSize() {
	return size;
}
long int DynamicArrayLongInt::GetValuen(int n) {
	return value[n];
}
long int *DynamicArrayLongInt::GetValue() {
	return value;
}

void DynamicArrayLongInt::SetValue(int n, long int v) {
	if (n > size) { return; }
	value[n] = v;
}
void DynamicArrayLongInt::SetValues(long int *array, int arraysize) {
	long int *tmp;
	tmp = new long int[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DynamicArrayLongInt::InsValues(int n, long int *v, int vsize) {
	long int *tmp;
	if (n > size) { return; }
	tmp = new long int[size + vsize];
	for (int i = 0; i < n; i++) {
		tmp[i] = value[i];
	}
	for (int i = n; i < n + vsize; i++) {
		tmp[i] = v[i - n];
	}
	for (int i = n + vsize; i < size + vsize; i++) {
		tmp[i] = value[i - vsize];
	}
	delete value;
	value = tmp;
	size += vsize;
}
void DynamicArrayLongInt::InsValue(int n, long int v) {
	InsValues(n, &v, 1);
}
void DynamicArrayLongInt::AddValues(long int *v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArrayLongInt::AddValue(long int v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArrayLongInt::Cat(DynamicArrayLongInt *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArrayLongInt::DelValue(int n) {
	if (n >= size) { return; }
	long int *tmp;
	tmp = new long int[size - 1];
	for (int i = 0; i < n; i++) {
		tmp[i] = value[i];
	}
	for (int i = n + 1; i < size; i++) {
		tmp[i - 1] = value[i];
	}
	delete value;
	value = tmp;
	size--;
}
