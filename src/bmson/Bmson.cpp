#include "Bmson.h"

Bmson::Bmson() {
	version = new DynamicArrayChar;
	info = new BmsonInfo;
	lines = new DynamicArray_BarLine;
	bpm_events = new DynamicArray_BpmEvent;
	stop_events = new DynamicArray_StopEvent;
	sound_channels = new DynamicArray_SoundChannel;
	bga = new BGA;
}
Bmson::~Bmson() {
	delete version;
	delete info;
	delete lines;
	delete bpm_events;
	delete stop_events;
	delete sound_channels;
	delete bga;
	version = 0;
	info = 0;
	lines = 0;
	bpm_events = 0;
	stop_events = 0;
	sound_channels = 0;
	bga = 0;
}

DAChar Bmson::GetVersion() {
	return version;
}
BmsonInfo* Bmson::GetInfo() {
	return info;
}
DA_BarLine Bmson::GetLines() {
	return lines;
}
DA_BpmEvent Bmson::GetBpmEvents() {
	return bpm_events;
}
DA_StopEvent Bmson::GetStopEvents() {
	return stop_events;
}
DA_SoundChannel Bmson::GetSoundChannels() {
	return sound_channels;
}
BGA* Bmson::GetBga() {
	return bga;
}

void Bmson::SetVersion(String value) {
	version->SetValues(value->GetValue(), value->GetSize());
}
void Bmson::SetInfo(BmsonInfo* value) {
	info->SetTitle(value->GetTitle());
	info->SetSubtitle(value->GetSubtitle());
	info->SetArtist(value->GetArtist());
	info->SetSubartists(value->GetSubartists());
	info->SetGenre(value->GetGenre());
	info->SetModeHint(value->GetModeHint());
	info->SetChartName(value->GetChartName());
	info->SetLevel(value->GetLevel());
	info->SetInitBpm(value->GetInitBpm());
	info->SetJudgeRank(value->GetJudgeRank());
	info->SetTotal(value->GetTotal());
	info->SetBackImage(value->GetBackImage());
	info->SetEyecatchImage(value->GetEyecatchImage());
	info->SetBannerImage(value->GetBannerImage());
	info->SetPreviewMusic(value->GetPreviewMusic());
	info->SetResolution(value->GetResolution());
}
void Bmson::SetLines(DA_BarLine value) {
	lines->SetValues(value->GetValue(), value->GetSize());
}
void Bmson::SetBpmEvents(DA_BpmEvent value) {
	bpm_events->SetValues(value->GetValue(), value->GetSize());
}
void Bmson::SetStopEvents(DA_StopEvent value) {
	stop_events->SetValues(value->GetValue(), value->GetSize());
}
void Bmson::SetSoundChannels(DA_SoundChannel value) {
	sound_channels->SetValues(value->GetValue(), value->GetSize());
}
void Bmson::SetBga(BGA* value) {
	bga->SetBgaHeader(value->GetBgaHeader());
	bga->SetBgaEvents(value->GetBgaEvents());
	bga->SetLayerEvents(value->GetLayerEvents());
	bga->SetPoorEvents(value->GetPoorEvents());
}