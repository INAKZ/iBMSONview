#include "DA_Note.h"

DA_Note::DA_Note() {
	size = 1;
	value = new Note[size];
	value[0].SetX(0);
	value[0].SetY(0);
	value[0].SetL(0);
	value[0].SetC(false);
}
DA_Note::DA_Note(int setsize) {
	size = setsize;
	value = new Note[size];
	Zeros();
}
DA_Note::~DA_Note() {
	delete value;
}

void DA_Note::Zeros() {
	for (int i = 0; i < size; i++) {
		value[i].SetX(0);
		value[i].SetY(0);
		value[i].SetL(0);
		value[i].SetC(false);
	}
}

int DA_Note::GetSize() {
	return size;
}
Note DA_Note::GetValuen(int n) {
	return value[n];
}
Note* DA_Note::GetValue() {
	return value;
}

void DA_Note::SetValue(int n, Note v) {
	if (n > size) { return; }
	value[n] = v;
}
void DA_Note::SetValues(Note* array, int arraysize) {
	Note* tmp;
	tmp = new Note[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DA_Note::InsValues(int n, Note* v, int vsize) {
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
	delete value;
	value = tmp;
	size += vsize;
}
void DA_Note::InsValue(int n, Note v) {
	InsValues(n, &v, 1);
}
void DA_Note::AddValues(Note* v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DA_Note::AddValue(Note v) {
	InsValues(GetSize(), &v, 1);
}
void DA_Note::Cat(DA_Note* src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DA_Note::DelValue(int n) {
	if (n >= size) { return; }
	Note* tmp;
	tmp = new Note[size - 1];
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
