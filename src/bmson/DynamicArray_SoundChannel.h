#pragma once
#include "../util/util.h"
#include "SoundChannel.h"

class DynamicArray_SoundChannel {
public:
	DynamicArray_SoundChannel();
	DynamicArray_SoundChannel(int setsize);
	~DynamicArray_SoundChannel();

	void Zeros();

	int GetSize();
	SoundChannel GetValuen(int n);
	SoundChannel* GetValue();

	void SetValue(int n, SoundChannel v);
	void SetValues(SoundChannel* array, int arraysize);

	void InsValues(int n, SoundChannel* v, int vsize);
	void InsValue(int n, SoundChannel v);
	void AddValues(SoundChannel* v, int vsize);
	void AddValue(SoundChannel v);
	void Cat(DynamicArray_SoundChannel *src);
	void DelValue(int n);

private:
	int size;
	SoundChannel* value;
};
typedef DynamicArray_SoundChannel* DA_SoundChannel;