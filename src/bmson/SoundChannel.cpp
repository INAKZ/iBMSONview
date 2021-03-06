#include "SoundChannel.h"

SoundChannel::SoundChannel() {
	name = new DynamicArrayChar;
	notes = new DynamicArray_Note;
}
SoundChannel::~SoundChannel() {
	delete name;
	delete notes;
	name = 0;
	notes = 0;
}

void SoundChannel::Zeros() {
	name->Zeros();
	notes->Zeros();
}

DAChar SoundChannel::GetName() {
	return name;
}
DA_Note SoundChannel::GetNotes() {
	return notes;
}

void SoundChannel::SetName(DAChar value) {
	name->SetValues(value->GetValue(), value->GetSize());
}
void SoundChannel::SetNotes(DA_Note value) {
	notes->SetValues(value->GetValue(), value->GetSize());
}