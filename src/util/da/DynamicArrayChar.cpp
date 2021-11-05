#include "DynamicArrayChar.h"

DynamicArrayChar::DynamicArrayChar() {
	size = 1;
	value = new char[size];
	value[0] = 0;
}
DynamicArrayChar::DynamicArrayChar(int setsize) {
	size = setsize;
	value = new char[size];
	ZerosChar(value, size);
}
DynamicArrayChar::DynamicArrayChar(int setsize, char* setvalue) {
	size = setsize;
	SetValues(setvalue, setsize);
}
DynamicArrayChar::~DynamicArrayChar() {
	delete value;
}

void DynamicArrayChar::Zeros() {
	ZerosChar(value, size);
}

int DynamicArrayChar::GetSize() {
	return size;
}
char DynamicArrayChar::GetValuen(int n) {
	return value[n];
}
char *DynamicArrayChar::GetValue() {
	return value;
}

void DynamicArrayChar::SetValue(int n, char v) {
	if (n > size) { return; }
	value[n] = v;
}
void DynamicArrayChar::SetValues(char *array, int arraysize) {
	char *tmp;
	tmp = new char[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DynamicArrayChar::InsValues(int n, char *v, int vsize) {
	char *tmp;
	if (n > size) { return; }
	tmp = new char[size + vsize];
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
void DynamicArrayChar::InsValue(int n, char v) {
	InsValues(n, &v, 1);
}
void DynamicArrayChar::AddValues(char *v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArrayChar::AddValue(char v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArrayChar::Cat(DynamicArrayChar *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArrayChar::DelValue(int n) {
	if (n >= size) { return; }
	char *tmp;
	tmp = new char[size - 1];
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
