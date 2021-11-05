#include "DA_BGAHeader.h"

DA_BGAHeader::DA_BGAHeader() {
	size = 1;
	value = new BGAHeader[size];
	value[0].SetId(0);
	value[0].SetName(new DAChar);
}
DA_BGAHeader::DA_BGAHeader(int setsize) {
	size = setsize;
	value = new BGAHeader[size];
	Zeros();
}
DA_BGAHeader::~DA_BGAHeader() {
	delete value;
}

void DA_BGAHeader::Zeros() {
	for (int i = 0; i < size; i++) {
		value[i].SetId(0);
		value[i].SetName(new DAChar);
	}
}

int DA_BGAHeader::GetSize() {
	return size;
}
BGAHeader DA_BGAHeader::GetValuen(int n) {
	return value[n];
}
BGAHeader* DA_BGAHeader::GetValue() {
	return value;
}

void DA_BGAHeader::SetValue(int n, BGAHeader v) {
	if (n > size) { return; }
	value[n] = v;
}
void DA_BGAHeader::SetValues(BGAHeader* array, int arraysize) {
	BGAHeader* tmp;
	tmp = new BGAHeader[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DA_BGAHeader::InsValues(int n, BGAHeader* v, int vsize) {
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
void DA_BGAHeader::InsValue(int n, BGAHeader v) {
	InsValues(n, &v, 1);
}
void DA_BGAHeader::AddValues(BGAHeader* v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DA_BGAHeader::AddValue(BGAHeader v) {
	InsValues(GetSize(), &v, 1);
}
void DA_BGAHeader::Cat(DA_BGAHeader* src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DA_BGAHeader::DelValue(int n) {
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
