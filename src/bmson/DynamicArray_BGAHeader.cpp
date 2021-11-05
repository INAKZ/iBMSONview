#include "DynamicArray_BGAHeader.h"

DynamicArray_BGAHeader::DynamicArray_BGAHeader() {
	size = 1;
	value = new BGAHeader[size];
	value[0].SetId(0);
	value[0].SetName(new DynamicArrayChar);
}
DynamicArray_BGAHeader::DynamicArray_BGAHeader(int setsize) {
	size = setsize;
	value = new BGAHeader[size];
	Zeros();
}
DynamicArray_BGAHeader::~DynamicArray_BGAHeader() {
	delete value;
}

void DynamicArray_BGAHeader::Zeros() {
	for (int i = 0; i < size; i++) {
		value[i].SetId(0);
		value[i].SetName(new DynamicArrayChar);
	}
}

int DynamicArray_BGAHeader::GetSize() {
	return size;
}
BGAHeader DynamicArray_BGAHeader::GetValuen(int n) {
	return value[n];
}
BGAHeader* DynamicArray_BGAHeader::GetValue() {
	return value;
}

void DynamicArray_BGAHeader::SetValue(int n, BGAHeader v) {
	if (n > size) { return; }
	value[n] = v;
}
void DynamicArray_BGAHeader::SetValues(BGAHeader* array, int arraysize) {
	BGAHeader* tmp;
	tmp = new BGAHeader[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DynamicArray_BGAHeader::InsValues(int n, BGAHeader* v, int vsize) {
	BGAHeader* tmp;
	if (n > size) { return; }
	tmp = new BGAHeader[size + vsize];
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
void DynamicArray_BGAHeader::InsValue(int n, BGAHeader v) {
	InsValues(n, &v, 1);
}
void DynamicArray_BGAHeader::AddValues(BGAHeader* v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArray_BGAHeader::AddValue(BGAHeader v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArray_BGAHeader::Cat(DynamicArray_BGAHeader *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArray_BGAHeader::DelValue(int n) {
	if (n >= size) { return; }
	BGAHeader* tmp;
	tmp = new BGAHeader[size - 1];
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
