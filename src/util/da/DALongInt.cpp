#include "DALongInt.h"

DALongInt::DALongInt() {
	size = 1;
	value = new long int[size];
	value[0] = 0;
}
DALongInt::DALongInt(int setsize) {
	size = setsize;
	value = new long int[size];
	ZerosLongInt(value, size);
}
DALongInt::~DALongInt() {
	delete value;
}

void DALongInt::Zeros() {
	ZerosLongInt(value, size);
}

int DALongInt::GetSize() {
	return size;
}
long int DALongInt::GetValuen(int n) {
	return value[n];
}
long int *DALongInt::GetValue() {
	return value;
}

void DALongInt::SetValue(int n, long int v) {
	if (n > size) { return; }
	value[n] = v;
}
void DALongInt::SetValues(long int *array, int arraysize) {
	long int *tmp;
	tmp = new long int[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DALongInt::InsValues(int n, long int *v, int vsize) {
	long int *tmp;
	if (n > size) { return; }
	tmp = new long int[size + vsize];
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
void DALongInt::InsValue(int n, long int v) {
	InsValues(n, &v, 1);
}
void DALongInt::AddValues(long int *v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DALongInt::AddValue(long int v) {
	InsValues(GetSize(), &v, 1);
}
void DALongInt::Cat(DALongInt *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DALongInt::DelValue(int n) {
	if (n >= size) { return; }
	long int *tmp;
	tmp = new long int[size - 1];
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
