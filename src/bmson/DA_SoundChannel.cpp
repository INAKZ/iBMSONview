#include "DA_SoundChannel.h"

DA_SoundChannel::DA_SoundChannel() {
	size = 1;
	value = new SoundChannel[size];
	value[0].SetName(new DAChar);
	value[0].SetNotes(new DA_Note);
}
DA_SoundChannel::DA_SoundChannel(int setsize) {
	size = setsize;
	value = new SoundChannel[size];
	Zeros();
}
DA_SoundChannel::~DA_SoundChannel() {
	delete value;
}

void DA_SoundChannel::Zeros() {
	for (int i = 0; i < size; i++) {
		value[i].SetName(new DAChar);
		value[i].SetNotes(new DA_Note);
	}
}

int DA_SoundChannel::GetSize() {
	return size;
}
SoundChannel DA_SoundChannel::GetValuen(int n) {
	return value[n];
}
SoundChannel* DA_SoundChannel::GetValue() {
	return value;
}

void DA_SoundChannel::SetValue(int n, SoundChannel v) {
	if (n > size) { return; }
	value[n] = v;
}
void DA_SoundChannel::SetValues(SoundChannel* array, int arraysize) {
	SoundChannel* tmp;
	tmp = new SoundChannel[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete value;
	value = tmp;
	size = arraysize;
}

void DA_SoundChannel::InsValues(int n, SoundChannel* v, int vsize) {
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
void DA_SoundChannel::InsValue(int n, SoundChannel v) {
	InsValues(n, &v, 1);
}
void DA_SoundChannel::AddValues(SoundChannel* v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DA_SoundChannel::AddValue(SoundChannel v) {
	InsValues(GetSize(), &v, 1);
}
void DA_SoundChannel::Cat(DA_SoundChannel* src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DA_SoundChannel::DelValue(int n) {
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
