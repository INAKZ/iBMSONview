#pragma once
#include "../util/util.h"
#include "DynamicArray_Note.h"

class SoundChannel {
public:
	SoundChannel();
	~SoundChannel();

	String GetName();
	DA_Note GetNotes();

	void SetName(String value);
	void SetNotes(DA_Note value);

private:
	String name;
	DA_Note notes;
};

