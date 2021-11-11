#include "DynamicArrayInt.h"

DynamicArrayInt::DynamicArrayInt() {
	size = 1;
	value = new int[size];
	value[0] = 0;
}
DynamicArrayInt::DynamicArrayInt(int setsize) {
	size = setsize;
	value = new int[size];
	ZerosInt(value, size);
}
DynamicArrayInt::~DynamicArrayInt() {
	delete[] value;
	value = 0;
}

void DynamicArrayInt::Zeros() {
	ZerosInt(value, size);
}

int DynamicArrayInt::GetSize() {
	return size;
}
int DynamicArrayInt::GetValuen(int n) {
	return value[n];
}
int *DynamicArrayInt::GetValue() {
	return value;
}

void DynamicArrayInt::SetSize(int n) {
	size = n;
}
void DynamicArrayInt::SetValue(int n, int v) {
	if (n > size) { return; }
	value[n] = v;
}
void DynamicArrayInt::SetValues(int *array, int arraysize) {
	int *tmp;
	tmp = new int[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete[] value;
	value = tmp;
	size = arraysize;
}

void DynamicArrayInt::InsValues(int n, int* v, int vsize) {
	int* tmp;
	if (n > size) { return; }
	tmp = new int[size + vsize];
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
void DynamicArrayInt::InsValue(int n, int v) {
	InsValues(n, &v, 1);
}
void DynamicArrayInt::AddValues(int *v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArrayInt::AddValue(int v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArrayInt::Cat(DynamicArrayInt *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArrayInt::DelValue(int n) {
	if (n >= size) { return; }
	int *tmp;
	tmp = new int[size - 1];
	for (int i = 0; i < n; i++) {
		tmp[i] = value[i];
	}
	for (int i = n+1; i < size; i++) {
		tmp[i-1] = value[i];
	}
	delete[] value;
	value = tmp;
	size--;
}
