#include "DynamicArray_DAChar.h"

DynamicArray_DAChar::DynamicArray_DAChar() {
	size = 1;
	value = new DynamicArrayChar[size];
	Zeros();
}
DynamicArray_DAChar::DynamicArray_DAChar(int setsize) {
	size = setsize;
	value = new DynamicArrayChar[size];
	Zeros();
}
DynamicArray_DAChar::~DynamicArray_DAChar() {
	delete value;
}

void DynamicArray_DAChar::Zeros() {
	for (int i = 0; i < GetSize(); i++) {
		value[i].Zeros();
	}
}

int DynamicArray_DAChar::GetSize() {
	return size;
}
DynamicArrayChar DynamicArray_DAChar::GetValuen(int n) {
	return value[n];
}
DAChar DynamicArray_DAChar::GetValue() {
	return value;
}

void DynamicArray_DAChar::SetValue(int n, DynamicArrayChar v) {
	if (n > size) { return; }
	value[n] = v;
}
void DynamicArray_DAChar::SetValues(DAChar array, int arraysize) {
	DAChar tmp;
	tmp = new DynamicArrayChar[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DynamicArray_DAChar::InsValues(int n, DAChar v, int vsize) {
	DAChar tmp;
	if (n > size) { return; }
	tmp = new DynamicArrayChar[size + vsize];
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
void DynamicArray_DAChar::InsValue(int n, DynamicArrayChar v) {
	InsValues(n, &v, 1);
}
void DynamicArray_DAChar::AddValues(DAChar v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArray_DAChar::AddValue(DynamicArrayChar v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArray_DAChar::Cat(DynamicArray_DAChar *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArray_DAChar::DelValue(int n) {
	if (n >= size) { return; }
	DAChar tmp;
	tmp = new DynamicArrayChar[size - 1];
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
