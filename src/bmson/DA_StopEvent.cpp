#include "DA_StopEvent.h"

DA_StopEvent::DA_StopEvent() {
	size = 1;
	value = new StopEvent[size];
	value[0].SetY(0);
	value[0].SetDuration(0);
}
DA_StopEvent::DA_StopEvent(int setsize) {
	size = setsize;
	value = new StopEvent[size];
	Zeros();
}
DA_StopEvent::~DA_StopEvent() {
	delete value;
}

void DA_StopEvent::Zeros() {
	for (int i = 0; i < size; i++) {
		value[0].SetY(0);
		value[0].SetDuration(0);
	}
}

int DA_StopEvent::GetSize() {
	return size;
}
StopEvent DA_StopEvent::GetValuen(int n) {
	return value[n];
}
StopEvent* DA_StopEvent::GetValue() {
	return value;
}

void DA_StopEvent::SetValue(int n, StopEvent v) {
	if (n > size) { return; }
	value[n] = v;
}
void DA_StopEvent::SetValues(StopEvent* array, int arraysize) {
	StopEvent* tmp;
	tmp = new StopEvent[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DA_StopEvent::InsValues(int n, StopEvent* v, int vsize) {
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
	delete value;
	value = tmp;
	size += vsize;
}
void DA_StopEvent::InsValue(int n, StopEvent v) {
	InsValues(n, &v, 1);
}
void DA_StopEvent::AddValues(StopEvent* v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DA_StopEvent::AddValue(StopEvent v) {
	InsValues(GetSize(), &v, 1);
}
void DA_StopEvent::Cat(DA_StopEvent* src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DA_StopEvent::DelValue(int n) {
	if (n >= size) { return; }
	StopEvent* tmp;
	tmp = new StopEvent[size - 1];
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
