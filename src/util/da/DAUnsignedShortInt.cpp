#include "DAUnsignedShortInt.h"

DAUnsignedShortInt::DAUnsignedShortInt() {
	size = 1;
	value = new unsigned short int[size];
	value[0] = 0;
}
DAUnsignedShortInt::DAUnsignedShortInt(int setsize) {
	size = setsize;
	value = new unsigned short int[size];
	ZerosUnsignedShortInt(value, size);
}
DAUnsignedShortInt::~DAUnsignedShortInt() {
	delete value;
}

void DAUnsignedShortInt::Zeros() {
	ZerosUnsignedShortInt(value, size);
}

int DAUnsignedShortInt::GetSize() {
	return size;
}
unsigned short int DAUnsignedShortInt::GetValuen(int n) {
	return value[n];
}
unsigned short int *DAUnsignedShortInt::GetValue() {
	return value;
}

void DAUnsignedShortInt::SetValue(int n, unsigned short int v) {
	if (n > size) { return; }
	value[n] = v;
}
void DAUnsignedShortInt::SetValues(unsigned short int *array, int arraysize) {
	unsigned short int *tmp;
	tmp = new unsigned short int[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DAUnsignedShortInt::InsValues(int n, unsigned short int *v, int vsize) {
	unsigned short int *tmp;
	if (n > size) { return; }
	tmp = new unsigned short int[size + vsize];
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
void DAUnsignedShortInt::InsValue(int n, unsigned short int v) {
	InsValues(n, &v, 1);
}
void DAUnsignedShortInt::AddValues(unsigned short int *v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DAUnsignedShortInt::AddValue(unsigned short int v) {
	InsValues(GetSize(), &v, 1);
}
void DAUnsignedShortInt::Cat(DAUnsignedShortInt *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DAUnsignedShortInt::DelValue(int n) {
	if (n >= size) { return; }
	unsigned short int *tmp;
	tmp = new unsigned short int[size - 1];
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
