#include "DynamicArrayUnsignedLongInt.h"

DynamicArrayUnsignedLongInt::DynamicArrayUnsignedLongInt() {
	size = 1;
	value = new unsigned long int[size];
	value[0] = 0;
}
DynamicArrayUnsignedLongInt::DynamicArrayUnsignedLongInt(int setsize) {
	size = setsize;
	value = new unsigned long int[size];
	ZerosUnsignedLongInt(value, size);
}
DynamicArrayUnsignedLongInt::~DynamicArrayUnsignedLongInt() {
	delete[] value;
}

void DynamicArrayUnsignedLongInt::Zeros() {
	ZerosUnsignedLongInt(value, size);
}

int DynamicArrayUnsignedLongInt::GetSize() {
	return size;
}
unsigned long int DynamicArrayUnsignedLongInt::GetValuen(int n) {
	return value[n];
}
unsigned long int* DynamicArrayUnsignedLongInt::GetValue() {
	return value;
}

void DynamicArrayUnsignedLongInt::SetValue(int n, unsigned long int v) {
	if (n > size) { return; }
	value[n] = v;
}
void DynamicArrayUnsignedLongInt::SetValues(unsigned long int* array, int arraysize) {
	unsigned long int* tmp;
	tmp = new unsigned long int[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete[] value;
	value = tmp;
	size = arraysize;
}

void DynamicArrayUnsignedLongInt::InsValues(int n, unsigned long int* v, int vsize) {
	unsigned long int* tmp;
	if (n > size) { return; }
	tmp = new unsigned long int[size + vsize];
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
void DynamicArrayUnsignedLongInt::InsValue(int n, unsigned long int v) {
	InsValues(n, &v, 1);
}
void DynamicArrayUnsignedLongInt::AddValues(unsigned long int* v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArrayUnsignedLongInt::AddValue(unsigned long int v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArrayUnsignedLongInt::Cat(DynamicArrayUnsignedLongInt *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArrayUnsignedLongInt::DelValue(int n) {
	if (n >= size) { return; }
	unsigned long int* tmp;
	tmp = new unsigned long int[size - 1];
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
