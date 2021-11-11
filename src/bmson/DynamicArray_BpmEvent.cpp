#include "DynamicArray_BpmEvent.h"

DynamicArray_BpmEvent::DynamicArray_BpmEvent() {
	size = 0;
	value = new BpmEvent[size];
	Zeros();
}
DynamicArray_BpmEvent::DynamicArray_BpmEvent(int setsize) {
	size = setsize;
	value = new BpmEvent[size];
	Zeros();
}
DynamicArray_BpmEvent::~DynamicArray_BpmEvent() {
	delete[] value;
	value = 0;
}

void DynamicArray_BpmEvent::Zeros() {
	for (int i = 0; i < size; i++) {
		value[i].SetY(0);
		value[i].SetBpm(0);
	}
}

int DynamicArray_BpmEvent::GetSize() {
	return size;
}
BpmEvent DynamicArray_BpmEvent::GetValuen(int n) {
	return value[n];
}
BpmEvent* DynamicArray_BpmEvent::GetValue() {
	return value;
}

void DynamicArray_BpmEvent::SetSize(int n) {
	size = n;
}
void DynamicArray_BpmEvent::SetValue(int n, BpmEvent v) {
	if (n > size) { return; }
	value[n] = v;
}
void DynamicArray_BpmEvent::SetValues(BpmEvent* array, int arraysize) {
	BpmEvent* tmp;
	tmp = new BpmEvent[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete[] value;
	value = tmp;
	size = arraysize;
}

void DynamicArray_BpmEvent::InsValues(int n, BpmEvent* v, int vsize) {
	BpmEvent* tmp;
	if (n > size) { return; }
	tmp = new BpmEvent[size + vsize];
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
void DynamicArray_BpmEvent::InsValue(int n, BpmEvent v) {
	InsValues(n, &v, 1);
}
void DynamicArray_BpmEvent::AddValues(BpmEvent* v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArray_BpmEvent::AddValue(BpmEvent v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArray_BpmEvent::Cat(DynamicArray_BpmEvent *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArray_BpmEvent::DelValue(int n) {
	if (n >= size) { return; }
	BpmEvent* tmp;
	tmp = new BpmEvent[size - 1];
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
