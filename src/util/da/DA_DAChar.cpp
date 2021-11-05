#include "DA_DAChar.h"

DA_DAChar::DA_DAChar() {
	size = 1;
	value = new DAChar[size];
	Zeros();
}
DA_DAChar::DA_DAChar(int setsize) {
	size = setsize;
	value = new DAChar[size];
	Zeros();
}
DA_DAChar::~DA_DAChar() {
	delete value;
}

void DA_DAChar::Zeros() {
	for (int i = 0; i < GetSize(); i++) {
		value[i].Zeros();
	}
}

int DA_DAChar::GetSize() {
	return size;
}
DAChar DA_DAChar::GetValuen(int n) {
	return value[n];
}
DAChar* DA_DAChar::GetValue() {
	return value;
}

void DA_DAChar::SetValue(int n, DAChar v) {
	if (n > size) { return; }
	value[n] = v;
}
void DA_DAChar::SetValues(DAChar* array, int arraysize) {
	DAChar* tmp;
	tmp = new DAChar[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DA_DAChar::InsValues(int n, DAChar* v, int vsize) {
	DAChar* tmp;
	if (n > size) { return; }
	tmp = new DAChar[size + vsize];
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
void DA_DAChar::InsValue(int n, DAChar v) {
	InsValues(n, &v, 1);
}
void DA_DAChar::AddValues(DAChar* v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DA_DAChar::AddValue(DAChar v) {
	InsValues(GetSize(), &v, 1);
}
void DA_DAChar::Cat(DA_DAChar* src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DA_DAChar::DelValue(int n) {
	if (n >= size) { return; }
	DAChar* tmp;
	tmp = new DAChar[size - 1];
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
