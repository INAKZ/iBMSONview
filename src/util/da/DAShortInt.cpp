#include "DAShortInt.h"

DAShortInt::DAShortInt() {
	size = 1;
	value = new short int[size];
	value[0] = 0;
}
DAShortInt::DAShortInt(int setsize) {
	size = setsize;
	value = new short int[size];
	ZerosShortInt(value, size);
}
DAShortInt::~DAShortInt() {
	delete value;
}

void DAShortInt::Zeros() {
	ZerosShortInt(value, size);
}

int DAShortInt::GetSize() {
	return size;
}
short int DAShortInt::GetValuen(int n) {
	return value[n];
}
short int* DAShortInt::GetValue() {
	return value;
}

void DAShortInt::SetValue(int n, short int v) {
	if (n > size) { return; }
	value[n] = v;
}
void DAShortInt::SetValues(short int* array, int arraysize) {
	short int* tmp;
	tmp = new short int[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DAShortInt::InsValues(int n, short int* v, int vsize) {
	short int* tmp;
	if (n > size) { return; }
	tmp = new short int[size + vsize];
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
void DAShortInt::InsValue(int n, short int v) {
	InsValues(n, &v, 1);
}
void DAShortInt::AddValues(short int* v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DAShortInt::AddValue(short int v) {
	InsValues(GetSize(), &v, 1);
}
void DAShortInt::Cat(DAShortInt* src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DAShortInt::DelValue(int n) {
	if (n >= size) { return; }
	short int* tmp;
	tmp = new short int[size - 1];
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
