#include "DAUnsignedLongInt.h"

DAUnsignedLongInt::DAUnsignedLongInt() {
	size = 1;
	value = new unsigned long int[size];
	value[0] = 0;
}
DAUnsignedLongInt::DAUnsignedLongInt(int setsize) {
	size = setsize;
	value = new unsigned long int[size];
	ZerosUnsignedLongInt(value, size);
}
DAUnsignedLongInt::~DAUnsignedLongInt() {
	delete value;
}

void DAUnsignedLongInt::Zeros() {
	ZerosUnsignedLongInt(value, size);
}

int DAUnsignedLongInt::GetSize() {
	return size;
}
unsigned long int DAUnsignedLongInt::GetValuen(int n) {
	return value[n];
}
unsigned long int* DAUnsignedLongInt::GetValue() {
	return value;
}

void DAUnsignedLongInt::SetValue(int n, unsigned long int v) {
	if (n > size) { return; }
	value[n] = v;
}
void DAUnsignedLongInt::SetValues(unsigned long int* array, int arraysize) {
	unsigned long int* tmp;
	tmp = new unsigned long int[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DAUnsignedLongInt::InsValues(int n, unsigned long int* v, int vsize) {
	unsigned long int* tmp;
	if (n > size) { return; }
	tmp = new unsigned long int[size + vsize];
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
void DAUnsignedLongInt::InsValue(int n, unsigned long int v) {
	InsValues(n, &v, 1);
}
void DAUnsignedLongInt::AddValues(unsigned long int* v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DAUnsignedLongInt::AddValue(unsigned long int v) {
	InsValues(GetSize(), &v, 1);
}
void DAUnsignedLongInt::Cat(DAUnsignedLongInt* src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DAUnsignedLongInt::DelValue(int n) {
	if (n >= size) { return; }
	unsigned long int* tmp;
	tmp = new unsigned long int[size - 1];
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
