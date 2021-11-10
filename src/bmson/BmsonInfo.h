#pragma once
#include "../util/util.h"

class BmsonInfo{
public:
	BmsonInfo();
	~BmsonInfo();

	String GetTitle();
	String GetSubtitle();
	String GetArtist();
	DA_String GetSubartists();
	String GetGenre();
	String GetModeHint();
	String GetChartName();
	unsigned long GetLevel();
	double GetInitBpm();
	double GetJudgeRank();
	double GetTotal();
	String GetBackImage();
	String GetEyecatchImage();
	String GetBannerImage();
	String GetPreviewMusic();
	unsigned long GetResolution();

	void SetTitle(String value);
	void SetSubtitle(String value);
	void SetArtist(String value);
	void SetSubartists(DA_String value);
	void SetGenre(String value);
	void SetModeHint(String value);
	void SetChartName(String value);
	void SetLevel(unsigned long value);
	void SetInitBpm(double value);
	void SetJudgeRank(double value);
	void SetTotal(double value);
	void SetBackImage(String value);
	void SetEyecatchImage(String value);
	void SetBannerImage(String value);
	void SetPreviewMusic(String value);
	void SetResolution(unsigned long value);

private:
	String title;
	String subtitle;
	String artist;
	DA_String subartists;
	String genre;
	String mode_hint;
	String chart_name;
	unsigned long level;
	double init_bpm;
	double judge_rank;
	double total;
	String back_image;
	String eyecatch_image;
	String banner_image;
	String preview_music;
	unsigned long resolution;
};

