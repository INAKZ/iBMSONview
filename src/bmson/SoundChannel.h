#pragma once
#include "../util/util.h"
#include "DynamicArray_Note.h"

class SoundChannel {
public:
	SoundChannel();
	~SoundChannel();

	DAChar GetName();
	DA_Note GetNotes();

	void SetName(DAChar value);
	void SetNotes(DA_Note value);

private:
	DAChar name;
	DA_Note notes;
};

