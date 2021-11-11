#pragma once
#include "../util/util.h"
#include "BmsonInfo.h"
#include "DynamicArray_BarLine.h"
#include "DynamicArray_BpmEvent.h"
#include "DynamicArray_StopEvent.h"
#include "DynamicArray_SoundChannel.h"
#include "BGA.h"

class Bmson {
public:
	Bmson();
	~Bmson();

	void Zeros();

	DAChar GetVersion();
	BmsonInfo* GetInfo();
	DA_BarLine GetLines();
	DA_BpmEvent GetBpmEvents();
	DA_StopEvent GetStopEvents();
	DA_SoundChannel GetSoundChannels();
	BGA* GetBga();

	void SetVersion(DAChar value);
	void SetInfo(BmsonInfo* value);
	void SetLines(DA_BarLine value);
	void SetBpmEvents(DA_BpmEvent value);
	void SetStopEvents(DA_StopEvent value);
	void SetSoundChannels(DA_SoundChannel value);
	void SetBga(BGA* value);

private:
	DAChar version;
	BmsonInfo *info;
	DA_BarLine lines;
	DA_BpmEvent bpm_events;
	DA_StopEvent stop_events;
	DA_SoundChannel sound_channels;
	BGA *bga;
};

