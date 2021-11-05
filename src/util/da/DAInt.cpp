#include "DAInt.h"

DAInt::DAInt() {
	size = 1;
	value = new int[size];
	value[0] = 0;
}
DAInt::DAInt(int setsize) {
	size = setsize;
	value = new int[size];
	ZerosInt(value, size);
}
DAInt::~DAInt() {
	delete value;
}

void DAInt::Zeros() {
	ZerosInt(value, size);
}

int DAInt::GetSize() {
	return size;
}
int DAInt::GetValuen(int n) {
	return value[n];
}
int *DAInt::GetValue() {
	return value;
}

void DAInt::SetValue(int n, int v) {
	if (n > size) { return; }
	value[n] = v;
}
void DAInt::SetValues(int *array, int arraysize) {
	int *tmp;
	tmp = new int[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DAInt::InsValues(int n, int* v, int vsize) {
	int* tmp;
	if (n > size) { return; }
	tmp = new int[size + vsize];
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
void DAInt::InsValue(int n, int v) {
	InsValues(n, &v, 1);
}
void DAInt::AddValues(int *v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DAInt::AddValue(int v) {
	InsValues(GetSize(), &v, 1);
}
void DAInt::Cat(DAInt *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DAInt::DelValue(int n) {
	if (n >= size) { return; }
	int *tmp;
	tmp = new int[size - 1];
	for (int i = 0; i < n; i++) {
		tmp[i] = value[i];
	}
	for (int i = n+1; i < size; i++) {
		tmp[i-1] = value[i];
	}
	delete value;
	value = tmp;
	size--;
}
