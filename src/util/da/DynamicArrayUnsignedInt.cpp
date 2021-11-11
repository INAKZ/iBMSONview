#include "DynamicArrayUnsignedInt.h"

DynamicArrayUnsignedInt::DynamicArrayUnsignedInt() {
	size = 1;
	value = new unsigned int[size];
	value[0] = 0;
}
DynamicArrayUnsignedInt::DynamicArrayUnsignedInt(int setsize) {
	size = setsize;
	value = new unsigned int[size];
	ZerosUnsignedInt(value, size);
}
DynamicArrayUnsignedInt::~DynamicArrayUnsignedInt() {
	delete[] value;
}

void DynamicArrayUnsignedInt::Zeros() {
	ZerosUnsignedInt(value, size);
}

int DynamicArrayUnsignedInt::GetSize() {
	return size;
}
unsigned int DynamicArrayUnsignedInt::GetValuen(int n) {
	return value[n];
}
unsigned int *DynamicArrayUnsignedInt::GetValue() {
	return value;
}

void DynamicArrayUnsignedInt::SetSize(int n) {
	size = n;
}
void DynamicArrayUnsignedInt::SetValue(int n, unsigned int v) {
	if (n > size) { return; }
	value[n] = v;
}
void DynamicArrayUnsignedInt::SetValues(unsigned int *array, int arraysize) {
	unsigned int *tmp;
	tmp = new unsigned int[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete[] value;
	value = tmp;
	size = arraysize;
}

void DynamicArrayUnsignedInt::InsValues(int n, unsigned int *v, int vsize) {
	unsigned int *tmp;
	if (n > size) { return; }
	tmp = new unsigned int[size + vsize];
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
void DynamicArrayUnsignedInt::InsValue(int n, unsigned int v) {
	InsValues(n, &v, 1);
}
void DynamicArrayUnsignedInt::AddValues(unsigned int *v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArrayUnsignedInt::AddValue(unsigned int v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArrayUnsignedInt::Cat(DynamicArrayUnsignedInt *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArrayUnsignedInt::DelValue(int n) {
	if (n >= size) { return; }
	unsigned int *tmp;
	tmp = new unsigned int[size - 1];
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
