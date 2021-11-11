#include "BmsonInfo.h"

BmsonInfo::BmsonInfo() {
	char tmp[8] = "beat-7k";
	title = new DynamicArrayChar;
	subtitle = new DynamicArrayChar;
	artist = new DynamicArrayChar;
	subartists = new DynamicArray_String;
	genre = new DynamicArrayChar;
	mode_hint = new DynamicArrayChar(8, tmp);
	chart_name = new DynamicArrayChar;
	level = 0;
	init_bpm = 100;
	judge_rank = 100;
	total = 100;
	back_image = new DynamicArrayChar;
	eyecatch_image = new DynamicArrayChar;
	banner_image = new DynamicArrayChar;
	preview_music = new DynamicArrayChar;
	resolution = 240;
}
BmsonInfo::~BmsonInfo() {
	delete title;
	delete subtitle;
	delete artist;
	delete subartists;
	delete genre;
	delete mode_hint;
	delete chart_name;
	delete back_image;
	delete eyecatch_image;
	delete banner_image;
	delete preview_music;
	title = 0;
	subtitle = 0;
	artist = 0;
	subartists = 0;
	genre = 0;
	mode_hint = 0;
	chart_name = 0;
	back_image = 0;
	eyecatch_image = 0;
	banner_image = 0;
	preview_music = 0;
}

DAChar BmsonInfo::GetTitle() {
	return title;
}
DAChar BmsonInfo::GetSubtitle() {
	return subtitle;
}
DAChar BmsonInfo::GetArtist() {
	return artist;
}
DA_DAChar BmsonInfo::GetSubartists() {
	return subartists;
}
DAChar BmsonInfo::GetGenre() {
	return genre;
}
DAChar BmsonInfo::GetModeHint() {
	return mode_hint;
}
DAChar BmsonInfo::GetChartName() {
	return chart_name;
}
unsigned long BmsonInfo::GetLevel() {
	return level;
}
double BmsonInfo::GetInitBpm() {
	return init_bpm;
}
double BmsonInfo::GetJudgeRank() {
	return judge_rank;
}
double BmsonInfo::GetTotal() {
	return total;
}
DAChar BmsonInfo::GetBackImage() {
	return back_image;
}
DAChar BmsonInfo::GetEyecatchImage() {
	return eyecatch_image;
}
DAChar BmsonInfo::GetBannerImage() {
	return banner_image;
}
DAChar BmsonInfo::GetPreviewMusic() {
	return preview_music;
}
unsigned long BmsonInfo::GetResolution() {
	return resolution;
}

void BmsonInfo::SetTitle(DAChar value) {
	title->SetValues(value->GetValue(), value->GetSize());
}
void BmsonInfo::SetSubtitle(DAChar value) {
	subtitle->SetValues(value->GetValue(), value->GetSize());
}
void BmsonInfo::SetArtist(DAChar value) {
	artist->SetValues(value->GetValue(), value->GetSize());
}
void BmsonInfo::SetSubartists(DA_DAChar value) {
	subartists->SetValues(value->GetValue(), value->GetSize());
}
void BmsonInfo::SetGenre(DAChar value) {
	genre->SetValues(value->GetValue(), value->GetSize());
}
void BmsonInfo::SetModeHint(DAChar value) {
	mode_hint->SetValues(value->GetValue(), value->GetSize());
}
void BmsonInfo::SetChartName(DAChar value) {
	chart_name->SetValues(value->GetValue(), value->GetSize());
}
void BmsonInfo::SetLevel(unsigned long value) {
	level = value;
}
void BmsonInfo::SetInitBpm(double value) {
	init_bpm = value;
}
void BmsonInfo::SetJudgeRank(double value) {
	judge_rank = value;
}
void BmsonInfo::SetTotal(double value) {
	total = value;
}
void BmsonInfo::SetBackImage(DAChar value) {
	back_image->SetValues(value->GetValue(), value->GetSize());
}
void BmsonInfo::SetEyecatchImage(DAChar value) {
	eyecatch_image->SetValues(value->GetValue(), value->GetSize());
}
void BmsonInfo::SetBannerImage(DAChar value) {
	banner_image->SetValues(value->GetValue(), value->GetSize());
}
void BmsonInfo::SetPreviewMusic(DAChar value) {
	preview_music->SetValues(value->GetValue(), value->GetSize());
}
void BmsonInfo::SetResolution(unsigned long value) {
	resolution = value;
}