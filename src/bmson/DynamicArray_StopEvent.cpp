#include "DynamicArray_StopEvent.h"

DynamicArray_StopEvent::DynamicArray_StopEvent() {
	size = 1;
	value = new StopEvent[size];
	Zeros();
}
DynamicArray_StopEvent::DynamicArray_StopEvent(int setsize) {
	size = setsize;
	value = new StopEvent[size];
	Zeros();
}
DynamicArray_StopEvent::~DynamicArray_StopEvent() {
	delete[] value;
}

void DynamicArray_StopEvent::Zeros() {
	for (int i = 0; i < size; i++) {
		value[0].SetY(0);
		value[0].SetDuration(0);
	}
}

int DynamicArray_StopEvent::GetSize() {
	return size;
}
StopEvent DynamicArray_StopEvent::GetValuen(int n) {
	return value[n];
}
StopEvent* DynamicArray_StopEvent::GetValue() {
	return value;
}

void DynamicArray_StopEvent::SetValue(int n, StopEvent v) {
	if (n > size) { return; }
	value[n] = v;
}
void DynamicArray_StopEvent::SetValues(StopEvent* array, int arraysize) {
	StopEvent* tmp;
	tmp = new StopEvent[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete[] value;
	value = tmp;
	size = arraysize;
}

void DynamicArray_StopEvent::InsValues(int n, StopEvent* v, int vsize) {
	StopEvent* tmp;
	if (n > size) { return; }
	tmp = new StopEvent[size + vsize];
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
void DynamicArray_StopEvent::InsValue(int n, StopEvent v) {
	InsValues(n, &v, 1);
}
void DynamicArray_StopEvent::AddValues(StopEvent* v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArray_StopEvent::AddValue(StopEvent v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArray_StopEvent::Cat(DynamicArray_StopEvent *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArray_StopEvent::DelValue(int n) {
	if (n >= size) { return; }
	StopEvent* tmp;
	tmp = new StopEvent[size - 1];
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
