#pragma once
#include "../util/util.h"

class BmsonInfo{
public:
	BmsonInfo();
	~BmsonInfo();

	DAChar GetTitle();
	DAChar GetSubtitle();
	DAChar GetArtist();
	DA_DAChar GetSubartists();
	DAChar GetGenre();
	DAChar GetModeHint();
	DAChar GetChartName();
	unsigned long GetLevel();
	double GetInitBpm();
	double GetJudgeRank();
	double GetTotal();
	DAChar GetBackImage();
	DAChar GetEyecatchImage();
	DAChar GetBannerImage();
	DAChar GetPreviewMusic();
	unsigned long GetResolution();

	void SetTitle(DAChar value);
	void SetSubtitle(DAChar value);
	void SetArtist(DAChar value);
	void SetSubartists(DA_DAChar value);
	void SetGenre(DAChar value);
	void SetModeHint(DAChar value);
	void SetChartName(DAChar value);
	void SetLevel(unsigned long value);
	void SetInitBpm(double value);
	void SetJudgeRank(double value);
	void SetTotal(double value);
	void SetBackImage(DAChar value);
	void SetEyecatchImage(DAChar value);
	void SetBannerImage(DAChar value);
	void SetPreviewMusic(DAChar value);
	void SetResolution(unsigned long value);

private:
	DAChar title;
	DAChar subtitle;
	DAChar artist;
	DA_DAChar subartists;
	DAChar genre;
	DAChar mode_hint;
	DAChar chart_name;
	unsigned long level;
	double init_bpm;
	double judge_rank;
	double total;
	DAChar back_image;
	DAChar eyecatch_image;
	DAChar banner_image;
	DAChar preview_music;
	unsigned long resolution;
};

