#include "DA_BarLine.h"

DA_BarLine::DA_BarLine() {
	size = 1;
	value = new BarLine[size];
	value[0].SetY(0);
}
DA_BarLine::DA_BarLine(int setsize) {
	size = setsize;
	value = new BarLine[size];
	Zeros();
}
DA_BarLine::~DA_BarLine() {
	delete value;
}

void DA_BarLine::Zeros() {
	for (int i = 0; i < size; i++) {
		value[i].SetY(0);
	}
}

int DA_BarLine::GetSize() {
	return size;
}
BarLine DA_BarLine::GetValuen(int n) {
	return value[n];
}
BarLine* DA_BarLine::GetValue() {
	return value;
}

void DA_BarLine::SetValue(int n, BarLine v) {
	if (n > size) { return; }
	value[n] = v;
}
void DA_BarLine::SetValues(BarLine* array, int arraysize) {
	BarLine* tmp;
	tmp = new BarLine[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DA_BarLine::InsValues(int n, BarLine* v, int vsize) {
	BarLine* tmp;
	if (n > size) { return; }
	tmp = new BarLine[size + vsize];
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
void DA_BarLine::InsValue(int n, BarLine v) {
	InsValues(n, &v, 1);
}
void DA_BarLine::AddValues(BarLine* v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DA_BarLine::AddValue(BarLine v) {
	InsValues(GetSize(), &v, 1);
}
void DA_BarLine::Cat(DA_BarLine* src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DA_BarLine::DelValue(int n) {
	if (n >= size) { return; }
	BarLine* tmp;
	tmp = new BarLine[size - 1];
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
