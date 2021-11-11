#include "DynamicArray_Note.h"

DynamicArray_Note::DynamicArray_Note() {
	size = 1;
	value = new Note[size];
	value[0].SetX(0);
	value[0].SetY(0);
	value[0].SetL(0);
	value[0].SetC(false);
}
DynamicArray_Note::DynamicArray_Note(int setsize) {
	size = setsize;
	value = new Note[size];
	Zeros();
}
DynamicArray_Note::~DynamicArray_Note() {
	delete[] value;
}

void DynamicArray_Note::Zeros() {
	for (int i = 0; i < size; i++) {
		value[i].SetX(0);
		value[i].SetY(0);
		value[i].SetL(0);
		value[i].SetC(false);
	}
}

int DynamicArray_Note::GetSize() {
	return size;
}
Note DynamicArray_Note::GetValuen(int n) {
	return value[n];
}
Note* DynamicArray_Note::GetValue() {
	return value;
}

void DynamicArray_Note::SetSize(int n) {
	size = n;
}
void DynamicArray_Note::SetValue(int n, Note v) {
	if (n > size) { return; }
	value[n] = v;
}
void DynamicArray_Note::SetValues(Note* array, int arraysize) {
	Note* tmp;
	tmp = new Note[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete[] value;
	value = tmp;
	size = arraysize;
}

void DynamicArray_Note::InsValues(int n, Note* v, int vsize) {
	Note* tmp;
	if (n > size) { return; }
	tmp = new Note[size + vsize];
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
void DynamicArray_Note::InsValue(int n, Note v) {
	InsValues(n, &v, 1);
}
void DynamicArray_Note::AddValues(Note* v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArray_Note::AddValue(Note v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArray_Note::Cat(DynamicArray_Note *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArray_Note::DelValue(int n) {
	if (n >= size) { return; }
	Note* tmp;
	tmp = new Note[size - 1];
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
