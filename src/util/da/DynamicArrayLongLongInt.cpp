#include "DynamicArrayLongLongInt.h"

DynamicArrayLongLongInt::DynamicArrayLongLongInt() {
	size = 1;
	value = new long long int[size];
	value[0] = 0;
}
DynamicArrayLongLongInt::DynamicArrayLongLongInt(int setsize) {
	size = setsize;
	value = new long long int[size];
	ZerosLongLongInt(value, size);
}
DynamicArrayLongLongInt::~DynamicArrayLongLongInt() {
	delete[] value;
	value = 0;
}

void DynamicArrayLongLongInt::Zeros() {
	ZerosLongLongInt(value, size);
}

int DynamicArrayLongLongInt::GetSize() {
	return size;
}
long long int DynamicArrayLongLongInt::GetValuen(int n) {
	return value[n];
}
long long int *DynamicArrayLongLongInt::GetValue() {
	return value;
}

void DynamicArrayLongLongInt::SetSize(int n) {
	size = n;
}
void DynamicArrayLongLongInt::SetValue(int n, long long int v) {
	if (n > size) { return; }
	value[n] = v;
}
void DynamicArrayLongLongInt::SetValues(long long int *array, int arraysize) {
	long long int *tmp;
	tmp = new long long int[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete[] value;
	value = tmp;
	size = arraysize;
}

void DynamicArrayLongLongInt::InsValues(int n, long long int *v, int vsize) {
	long long int *tmp;
	if (n > size) { return; }
	tmp = new long long int[size + vsize];
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
void DynamicArrayLongLongInt::InsValue(int n, long long int v) {
	InsValues(n, &v, 1);
}
void DynamicArrayLongLongInt::AddValues(long long int *v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArrayLongLongInt::AddValue(long long int v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArrayLongLongInt::Cat(DynamicArrayLongLongInt *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArrayLongLongInt::DelValue(int n) {
	if (n >= size) { return; }
	long long int *tmp;
	tmp = new long long int[size - 1];
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
