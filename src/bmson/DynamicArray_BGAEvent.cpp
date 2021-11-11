#include "DynamicArray_BGAEvent.h"

DynamicArray_BGAEvent::DynamicArray_BGAEvent() {
	size = 1;
	value = new BGAEvent[size];
	value[0].SetY(0);
	value[0].SetId(0);
}
DynamicArray_BGAEvent::DynamicArray_BGAEvent(int setsize) {
	size = setsize;
	value = new BGAEvent[size];
	Zeros();
}
DynamicArray_BGAEvent::~DynamicArray_BGAEvent() {
	delete[] value;
}

void DynamicArray_BGAEvent::Zeros() {
	for (int i = 0; i < size; i++) {
		value[i].SetY(0);
		value[i].SetId(0);
	}
}

int DynamicArray_BGAEvent::GetSize() {
	return size;
}
BGAEvent DynamicArray_BGAEvent::GetValuen(int n) {
	return value[n];
}
BGAEvent* DynamicArray_BGAEvent::GetValue() {
	return value;
}

void DynamicArray_BGAEvent::SetSize(int n) {
	size = n;
}
void DynamicArray_BGAEvent::SetValue(int n, BGAEvent v) {
	if (n > size) { return; }
	value[n] = v;
}
void DynamicArray_BGAEvent::SetValues(BGAEvent* array, int arraysize) {
	BGAEvent* tmp;
	tmp = new BGAEvent[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete[] value;
	value = tmp;
	size = arraysize;
}

void DynamicArray_BGAEvent::InsValues(int n, BGAEvent* v, int vsize) {
	BGAEvent* tmp;
	if (n > size) { return; }
	tmp = new BGAEvent[size + vsize];
	for (int i = 0; i < n; i++) {
		tmp[i] = value[i];
	}
	for (int i = n; i < n + vsize; i++) {
		tmp[i] = v[i - n];
	}
	for (int i = n + vsize; i < size + vsize; i++) {
		tmp[i] = value[i - vsize];
	}
	delete[] value;
	value = tmp;
	size += vsize;
}
void DynamicArray_BGAEvent::InsValue(int n, BGAEvent v) {
	InsValues(n, &v, 1);
}
void DynamicArray_BGAEvent::AddValues(BGAEvent* v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArray_BGAEvent::AddValue(BGAEvent v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArray_BGAEvent::Cat(DynamicArray_BGAEvent *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArray_BGAEvent::DelValue(int n) {
	if (n >= size) { return; }
	BGAEvent* tmp;
	tmp = new BGAEvent[size - 1];
	for (int i = 0; i < n; i++) {
		tmp[i] = value[i];
	}
	for (int i = n + 1; i < size; i++) {
		tmp[i - 1] = value[i];
	}
	delete[] value;
	value = tmp;
	size--;
}
