#include "DynamicArray_SoundChannel.h"

DynamicArray_SoundChannel::DynamicArray_SoundChannel() {
	size = 1;
	value = new SoundChannel[size];
	value[0].SetName(new DynamicArrayChar);
	value[0].SetNotes(new DynamicArray_Note);
}
DynamicArray_SoundChannel::DynamicArray_SoundChannel(int setsize) {
	size = setsize;
	value = new SoundChannel[size];
	Zeros();
}
DynamicArray_SoundChannel::~DynamicArray_SoundChannel() {
	delete value;
}

void DynamicArray_SoundChannel::Zeros() {
	for (int i = 0; i < size; i++) {
		value[i].SetName(new DynamicArrayChar);
		value[i].SetNotes(new DynamicArray_Note);
	}
}

int DynamicArray_SoundChannel::GetSize() {
	return size;
}
SoundChannel DynamicArray_SoundChannel::GetValuen(int n) {
	return value[n];
}
SoundChannel* DynamicArray_SoundChannel::GetValue() {
	return value;
}

void DynamicArray_SoundChannel::SetValue(int n, SoundChannel v) {
	if (n > size) { return; }
	value[n] = v;
}
void DynamicArray_SoundChannel::SetValues(SoundChannel* array, int arraysize) {
	SoundChannel* tmp;
	tmp = new SoundChannel[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DynamicArray_SoundChannel::InsValues(int n, SoundChannel* v, int vsize) {
	SoundChannel* tmp;
	if (n > size) { return; }
	tmp = new SoundChannel[size + vsize];
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
void DynamicArray_SoundChannel::InsValue(int n, SoundChannel v) {
	InsValues(n, &v, 1);
}
void DynamicArray_SoundChannel::AddValues(SoundChannel* v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArray_SoundChannel::AddValue(SoundChannel v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArray_SoundChannel::Cat(DynamicArray_SoundChannel *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArray_SoundChannel::DelValue(int n) {
	if (n >= size) { return; }
	SoundChannel* tmp;
	tmp = new SoundChannel[size - 1];
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
