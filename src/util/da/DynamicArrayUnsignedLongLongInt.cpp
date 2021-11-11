#include "DynamicArrayUnsignedLongLongInt.h"

DynamicArrayUnsignedLongLongInt::DynamicArrayUnsignedLongLongInt() {
	size = 1;
	value = new unsigned long long int[size];
	value[0] = 0;
}
DynamicArrayUnsignedLongLongInt::DynamicArrayUnsignedLongLongInt(int setsize) {
	size = setsize;
	value = new unsigned long long int[size];
	ZerosUnsignedLongLongInt(value, size);
}
DynamicArrayUnsignedLongLongInt::~DynamicArrayUnsignedLongLongInt() {
	delete[] value;
	value = 0;
}

void DynamicArrayUnsignedLongLongInt::Zeros() {
	ZerosUnsignedLongLongInt(value, size);
}

int DynamicArrayUnsignedLongLongInt::GetSize() {
	return size;
}
unsigned long long int DynamicArrayUnsignedLongLongInt::GetValuen(int n) {
	return value[n];
}
unsigned long long int *DynamicArrayUnsignedLongLongInt::GetValue() {
	return value;
}

void DynamicArrayUnsignedLongLongInt::SetSize(int n) {
	size = n;
}
void DynamicArrayUnsignedLongLongInt::SetValue(int n, unsigned long long int v) {
	if (n > size) { return; }
	value[n] = v;
}
void DynamicArrayUnsignedLongLongInt::SetValues(unsigned long long int *array, int arraysize) {
	unsigned long long int *tmp;
	tmp = new unsigned long long int[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete[] value;
	value = tmp;
	size = arraysize;
}

void DynamicArrayUnsignedLongLongInt::InsValues(int n, unsigned long long int *v, int vsize) {
	unsigned long long int *tmp;
	if (n > size) { return; }
	tmp = new unsigned long long int[size + vsize];
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
void DynamicArrayUnsignedLongLongInt::InsValue(int n, unsigned long long int v) {
	InsValues(n, &v, 1);
}
void DynamicArrayUnsignedLongLongInt::AddValues(unsigned long long int *v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArrayUnsignedLongLongInt::AddValue(unsigned long long int v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArrayUnsignedLongLongInt::Cat(DynamicArrayUnsignedLongLongInt *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArrayUnsignedLongLongInt::DelValue(int n) {
	if (n >= size) { return; }
	unsigned long long int *tmp;
	tmp = new unsigned long long int[size - 1];
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
