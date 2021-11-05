#include "DALongLongInt.h"

DALongLongInt::DALongLongInt() {
	size = 1;
	value = new long long int[size];
	value[0] = 0;
}
DALongLongInt::DALongLongInt(int setsize) {
	size = setsize;
	value = new long long int[size];
	ZerosLongLongInt(value, size);
}
DALongLongInt::~DALongLongInt() {
	delete value;
}

void DALongLongInt::Zeros() {
	ZerosLongLongInt(value, size);
}

int DALongLongInt::GetSize() {
	return size;
}
long long int DALongLongInt::GetValuen(int n) {
	return value[n];
}
long long int *DALongLongInt::GetValue() {
	return value;
}

void DALongLongInt::SetValue(int n, long long int v) {
	if (n > size) { return; }
	value[n] = v;
}
void DALongLongInt::SetValues(long long int *array, int arraysize) {
	long long int *tmp;
	tmp = new long long int[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DALongLongInt::InsValues(int n, long long int *v, int vsize) {
	long long int *tmp;
	if (n > size) { return; }
	tmp = new long long int[size + vsize];
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
void DALongLongInt::InsValue(int n, long long int v) {
	InsValues(n, &v, 1);
}
void DALongLongInt::AddValues(long long int *v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DALongLongInt::AddValue(long long int v) {
	InsValues(GetSize(), &v, 1);
}
void DALongLongInt::Cat(DALongLongInt *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DALongLongInt::DelValue(int n) {
	if (n >= size) { return; }
	long long int *tmp;
	tmp = new long long int[size - 1];
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
