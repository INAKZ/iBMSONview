#include "DAUnsignedLongLongInt.h"

DAUnsignedLongLongInt::DAUnsignedLongLongInt() {
	size = 1;
	value = new unsigned long long int[size];
	value[0] = 0;
}
DAUnsignedLongLongInt::DAUnsignedLongLongInt(int setsize) {
	size = setsize;
	value = new unsigned long long int[size];
	ZerosUnsignedLongLongInt(value, size);
}
DAUnsignedLongLongInt::~DAUnsignedLongLongInt() {
	delete value;
}

void DAUnsignedLongLongInt::Zeros() {
	ZerosUnsignedLongLongInt(value, size);
}

int DAUnsignedLongLongInt::GetSize() {
	return size;
}
unsigned long long int DAUnsignedLongLongInt::GetValuen(int n) {
	return value[n];
}
unsigned long long int *DAUnsignedLongLongInt::GetValue() {
	return value;
}

void DAUnsignedLongLongInt::SetValue(int n, unsigned long long int v) {
	if (n > size) { return; }
	value[n] = v;
}
void DAUnsignedLongLongInt::SetValues(unsigned long long int *array, int arraysize) {
	unsigned long long int *tmp;
	tmp = new unsigned long long int[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DAUnsignedLongLongInt::InsValues(int n, unsigned long long int *v, int vsize) {
	unsigned long long int *tmp;
	if (n > size) { return; }
	tmp = new unsigned long long int[size + vsize];
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
void DAUnsignedLongLongInt::InsValue(int n, unsigned long long int v) {
	InsValues(n, &v, 1);
}
void DAUnsignedLongLongInt::AddValues(unsigned long long int *v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DAUnsignedLongLongInt::AddValue(unsigned long long int v) {
	InsValues(GetSize(), &v, 1);
}
void DAUnsignedLongLongInt::Cat(DAUnsignedLongLongInt *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DAUnsignedLongLongInt::DelValue(int n) {
	if (n >= size) { return; }
	unsigned long long int *tmp;
	tmp = new unsigned long long int[size - 1];
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
