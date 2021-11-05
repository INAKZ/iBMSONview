#include "DADouble.h"

DADouble::DADouble() {
	size = 1;
	value = new double[size];
	value[0] = 0;
}
DADouble::DADouble(int setsize) {
	size = setsize;
	value = new double[size];
	ZerosDouble(value, size);
}
DADouble::~DADouble() {
	delete value;
}

void DADouble::Zeros() {
	ZerosDouble(value, size);
}

int DADouble::GetSize() {
	return size;
}
double DADouble::GetValuen(int n) {
	return value[n];
}
double *DADouble::GetValue() {
	return value;
}

void DADouble::SetValue(int n, double v) {
	if (n > size) { return; }
	value[n] = v;
}
void DADouble::SetValues(double *array, int arraysize) {
	double *tmp;
	tmp = new double[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DADouble::InsValues(int n, double *v, int vsize) {
	double *tmp;
	if (n > size) { return; }
	tmp = new double[size + vsize];
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
void DADouble::InsValue(int n, double v) {
	InsValues(n, &v, 1);
}
void DADouble::AddValues(double *v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DADouble::AddValue(double v) {
	InsValues(GetSize(), &v, 1);
}
void DADouble::Cat(DADouble *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DADouble::DelValue(int n) {
	if (n >= size) { return; }
	double *tmp;
	tmp = new double[size - 1];
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
