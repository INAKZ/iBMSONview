#include "DynamicArray_BGAHeader.h"

DynamicArray_BGAHeader::DynamicArray_BGAHeader() {
	size = 0;
	value = new BGAHeader[size];
	Zeros();
}
DynamicArray_BGAHeader::DynamicArray_BGAHeader(int setsize) {
	size = setsize;
	value = new BGAHeader[size];
	Zeros();
}
DynamicArray_BGAHeader::~DynamicArray_BGAHeader() {
	for (int i = 0; i < size; i++) {
		value[i].~BGAHeader();
	}
	delete[] value;
	value = 0;
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

void DynamicArray_BGAHeader::SetSize(int n) {
	size = n;
}
void DynamicArray_BGAHeader::SetValue(int n, BGAHeader v) {
	if (n > size) { return; }
	value[n].SetId(v.GetId());
	value[n].SetName(v.GetName());
}
void DynamicArray_BGAHeader::SetValues(BGAHeader* array, int arraysize) {
	BGAHeader* tmp;
	tmp = new BGAHeader[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i].SetId(array[i].GetId());
		tmp[i].SetName(array[i].GetName());
	}
	delete[] value;
	value = tmp;
	size = arraysize;
}

void DynamicArray_BGAHeader::InsValues(int n, BGAHeader* v, int vsize) {
	BGAHeader* tmp;
	if (n > size) { return; }
	tmp = new BGAHeader[size + vsize];
	for (int i = 0; i < n; i++) {
		tmp[i].SetId(value[i].GetId());
		tmp[i].SetName(value[i].GetName());
	}
	for (int i = n; i < n + vsize; i++) {
		tmp[i].SetId(v[i - n].GetId());
		tmp[i].SetName(v[i - n].GetName());
	}
	for (int i = n + vsize; i < size + vsize; i++) {
		tmp[i].SetId(value[i - vsize].GetId());
		tmp[i].SetName(value[i - vsize].GetName());
	}
	delete[] value;
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
		tmp[i].SetId(value[i].GetId());
		tmp[i].SetName(value[i].GetName());
	}
	for (int i = n + 1; i < size; i++) {
		tmp[i - 1].SetId(value[i].GetId());
		tmp[i - 1].SetName(value[i].GetName());
	}
	delete[] value;
	value = tmp;
	size--;
}
