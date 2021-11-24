#include "DynamicArray_Note.h"

DynamicArray_Note::DynamicArray_Note() {
	size = 0;
	value = new Note[size];
	Zeros();
}
DynamicArray_Note::DynamicArray_Note(int setsize) {
	size = setsize;
	value = new Note[size];
	Zeros();
}
DynamicArray_Note::~DynamicArray_Note() {
	delete[] value;
	value = 0;
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
	value[n].SetX(v.GetX());
	value[n].SetY(v.GetY());
	value[n].SetL(v.GetL());
	value[n].SetC(v.GetC());
}
void DynamicArray_Note::SetValues(Note* array, int arraysize) {
	Note* tmp;
	tmp = new Note[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i].SetX(array[i].GetX());
		tmp[i].SetY(array[i].GetY());
		tmp[i].SetL(array[i].GetL());
		tmp[i].SetC(array[i].GetC());
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
		tmp[i].SetX(value[i].GetX());
		tmp[i].SetY(value[i].GetY());
		tmp[i].SetL(value[i].GetL());
		tmp[i].SetC(value[i].GetC());
	}
	for (int i = n; i < n + vsize; i++) {
		tmp[i].SetX(v[i - n].GetX());
		tmp[i].SetY(v[i - n].GetY());
		tmp[i].SetL(v[i - n].GetL());
		tmp[i].SetC(v[i - n].GetC());
	}
	for (int i = n + vsize; i < size + vsize; i++) {
		tmp[i].SetX(value[i - vsize].GetX());
		tmp[i].SetY(value[i - vsize].GetY());
		tmp[i].SetL(value[i - vsize].GetL());
		tmp[i].SetC(value[i - vsize].GetC());
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
		tmp[i].SetX(value[i].GetX());
		tmp[i].SetY(value[i].GetY());
		tmp[i].SetL(value[i].GetL());
		tmp[i].SetC(value[i].GetC());
	}
	for (int i = n + 1; i < size; i++) {
		tmp[i - 1].SetX(value[i].GetX());
		tmp[i - 1].SetY(value[i].GetY());
		tmp[i - 1].SetL(value[i].GetL());
		tmp[i - 1].SetC(value[i].GetC());
	}
	delete[] value;
	value = tmp;
	size--;
}
