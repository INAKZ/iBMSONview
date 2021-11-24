#include "DynamicArray_BarLine.h"

DynamicArray_BarLine::DynamicArray_BarLine() {
	size = 0;
	value = new BarLine[size];
	Zeros();
}
DynamicArray_BarLine::DynamicArray_BarLine(int setsize) {
	size = setsize;
	value = new BarLine[size];
	Zeros();
}
DynamicArray_BarLine::~DynamicArray_BarLine() {
	delete[] value;
	value = 0;
}

void DynamicArray_BarLine::Zeros() {
	for (int i = 0; i < size; i++) {
		value[i].SetY(0);
	}
}

int DynamicArray_BarLine::GetSize() {
	return size;
}
BarLine DynamicArray_BarLine::GetValuen(int n) {
	return value[n];
}
BarLine* DynamicArray_BarLine::GetValue() {
	return value;
}

void DynamicArray_BarLine::SetSize(int n) {
	size = n;
}
void DynamicArray_BarLine::SetValue(int n, BarLine v) {
	if (n > size) { return; }
	value[n].SetY(v.GetY());
}
void DynamicArray_BarLine::SetValues(BarLine* array, int arraysize) {
	BarLine* tmp;
	tmp = new BarLine[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i].SetY(array[i].GetY());
	}
	delete[] value;
	value = tmp;
	size = arraysize;
}

void DynamicArray_BarLine::InsValues(int n, BarLine* v, int vsize) {
	BarLine* tmp;
	if (n > size) { return; }
	tmp = new BarLine[size + vsize];
	for (int i = 0; i < n; i++) {
		tmp[i].SetY(value[i].GetY());
	}
	for (int i = n; i < n + vsize; i++) {
		tmp[i].SetY(v[i - n].GetY());
	}
	for (int i = n + vsize; i < size + vsize; i++) {
		tmp[i].SetY(value[i - vsize].GetY());
	}
	delete[] value;
	value = tmp;
	size += vsize;
}
void DynamicArray_BarLine::InsValue(int n, BarLine v) {
	InsValues(n, &v, 1);
}
void DynamicArray_BarLine::AddValues(BarLine* v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArray_BarLine::AddValue(BarLine v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArray_BarLine::Cat(DynamicArray_BarLine *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArray_BarLine::DelValue(int n) {
	if (n >= size) { return; }
	BarLine* tmp;
	tmp = new BarLine[size - 1];
	for (int i = 0; i < n; i++) {
		tmp[i].SetY(value[i].GetY());
	}
	for (int i = n + 1; i < size; i++) {
		tmp[i - 1].SetY(value[i].GetY());
	}
	delete[] value;
	value = tmp;
	size--;
}
