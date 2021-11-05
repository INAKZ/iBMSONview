#pragma once
#include "../util/util.h"
#include "SoundChannel.h"

class DA_SoundChannel {
public:
	DA_SoundChannel();
	DA_SoundChannel(int setsize);
	~DA_SoundChannel();

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
	void Cat(DA_SoundChannel* src);
	void DelValue(int n);

private:
	int size;
	SoundChannel* value;
};