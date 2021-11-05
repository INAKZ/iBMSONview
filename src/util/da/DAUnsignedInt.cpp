#include "DAUnsignedInt.h"

DAUnsignedInt::DAUnsignedInt() {
	size = 1;
	value = new unsigned int[size];
	value[0] = 0;
}
DAUnsignedInt::DAUnsignedInt(int setsize) {
	size = setsize;
	value = new unsigned int[size];
	ZerosUnsignedInt(value, size);
}
DAUnsignedInt::~DAUnsignedInt() {
	delete value;
}

void DAUnsignedInt::Zeros() {
	ZerosUnsignedInt(value, size);
}

int DAUnsignedInt::GetSize() {
	return size;
}
unsigned int DAUnsignedInt::GetValuen(int n) {
	return value[n];
}
unsigned int *DAUnsignedInt::GetValue() {
	return value;
}

void DAUnsignedInt::SetValue(int n, unsigned int v) {
	if (n > size) { return; }
	value[n] = v;
}
void DAUnsignedInt::SetValues(unsigned int *array, int arraysize) {
	unsigned int *tmp;
	tmp = new unsigned int[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DAUnsignedInt::InsValues(int n, unsigned int *v, int vsize) {
	unsigned int *tmp;
	if (n > size) { return; }
	tmp = new unsigned int[size + vsize];
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
void DAUnsignedInt::InsValue(int n, unsigned int v) {
	InsValues(n, &v, 1);
}
void DAUnsignedInt::AddValues(unsigned int *v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DAUnsignedInt::AddValue(unsigned int v) {
	InsValues(GetSize(), &v, 1);
}
void DAUnsignedInt::Cat(DAUnsignedInt *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DAUnsignedInt::DelValue(int n) {
	if (n >= size) { return; }
	unsigned int *tmp;
	tmp = new unsigned int[size - 1];
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
