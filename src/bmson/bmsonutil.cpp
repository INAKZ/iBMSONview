#include "bmsonutil.h"

#include "Bmson.h"
#include "../util/util.h"
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include <fstream>

using namespace std;
using namespace rapidjson;

static constexpr char* KEY_VERSION = (char*)"version";

static constexpr char* KEY_INFO = (char*)"info";
static constexpr char* KEY_INFO_TITLE = (char*)"title";
static constexpr char* KEY_INFO_SUBTITLE = (char*)"subtitle";
static constexpr char* KEY_INFO_ARTIST = (char*)"artist";
static constexpr char* KEY_INFO_SUBARTISTS = (char*)"subartists";
static constexpr char* KEY_INFO_GENRE = (char*)"genre";
static constexpr char* KEY_INFO_MODEHINT = (char*)"mode_hint";
static constexpr char* KEY_INFO_CHARTNAME = (char*)"chart_name";
static constexpr char* KEY_INFO_LEVEL = (char*)"level";
static constexpr char* KEY_INFO_INITBPM = (char*)"init_bpm";
static constexpr char* KEY_INFO_JUDGERANK = (char*)"judge_rank";
static constexpr char* KEY_INFO_TOTAL = (char*)"total";
static constexpr char* KEY_INFO_BACKIMAGE = (char*)"back_image";
static constexpr char* KEY_INFO_EYECATCHIMAGE = (char*)"eyecatch_image";
static constexpr char* KEY_INFO_BANNERIMAGE = (char*)"banner_image";
static constexpr char* KEY_INFO_PREVIEWMUSIC = (char*)"preview_music";
static constexpr char* KEY_INFO_RESOLUTION = (char*)"resolution";

static constexpr char* KEY_LINES = (char*)"lines";
static constexpr char* KEY_LINES_Y = (char*)"y";

static constexpr char* KEY_BPMEVENTS = (char*)"bpm_events";
static constexpr char* KEY_BPMEVENTS_Y = (char*)"y";
static constexpr char* KEY_BPMEVENTS_BPM = (char*)"bpm";

static constexpr char* KEY_STOPEVENTS = (char*)"stop_events";
static constexpr char* KEY_STOPEVENTS_Y = (char*)"y";
static constexpr char* KEY_STOPEVENTS_DURATION = (char*)"duration";

static constexpr char* KEY_SOUNDCHANNELS = (char*)"sound_channels";
static constexpr char* KEY_SOUNDCHANNELS_NAME = (char*)"name";
static constexpr char* KEY_SOUNDCHANNELS_NOTES = (char*)"notes";
static constexpr char* KEY_SOUNDCHANNELS_NOTES_C = (char*)"c";
static constexpr char* KEY_SOUNDCHANNELS_NOTES_L = (char*)"l";
static constexpr char* KEY_SOUNDCHANNELS_NOTES_X = (char*)"x";
static constexpr char* KEY_SOUNDCHANNELS_NOTES_Y = (char*)"y";

static constexpr char* KEY_BGA = (char*)"bga";
static constexpr char* KEY_BGA_BGAHEADER = (char*)"bga_header";
static constexpr char* KEY_BGA_BGAHEADER_ID = (char*)"id";
static constexpr char* KEY_BGA_BGAHEADER_NAME = (char*)"name";
static constexpr char* KEY_BGA_BGAEVENTS = (char*)"bga_events";
static constexpr char* KEY_BGA_BGAEVENTS_ID = (char*)"id";
static constexpr char* KEY_BGA_BGAEVENTS_Y = (char*)"y";
static constexpr char* KEY_BGA_LAYEREVENTS = (char*)"layer_events";
static constexpr char* KEY_BGA_LAYEREVENTS_ID = (char*)"id";
static constexpr char* KEY_BGA_LAYEREVENTS_Y = (char*)"y";
static constexpr char* KEY_BGA_POOREVENTS = (char*)"poor_events";
static constexpr char* KEY_BGA_POOREVENTS_ID = (char*)"id";
static constexpr char* KEY_BGA_POOREVENTS_Y = (char*)"y";

static constexpr unsigned long DEFAULT_LEVEL = 0;
static constexpr double DEFAULT_INITBPM = 100;
static constexpr char* DEFAULT_MODEHINT = (char*)"beat-7k";
static constexpr double DEFAULT_JUDGERANK = 100;
static constexpr double DEFAULT_TOTAL = 100;
static constexpr unsigned long DEFAULT_RESOLUTION = 240;

static Document bmdoc;
static String tmps = 0;
static BarLine* tmpbl = 0;
static SoundChannel* tmpsc = 0;
static Note* tmpn = 0;
static DA_Note tmpns = 0;
static BpmEvent* tmpbe = 0;
static StopEvent* tmpse = 0;
static BGAHeader* tmpbgah = 0;
static BGAEvent* tmpbgae = 0;
static DA_BGAHeader tmpbgahs = 0;
static DA_BGAEvent tmpbgaes = 0;

static Bmson* bmson;
static String version = 0;
static BmsonInfo* info = 0;
static DA_BarLine lines = 0;
static DA_BpmEvent bpm_events = 0;
static DA_StopEvent stop_events = 0;
static DA_SoundChannel sound_channels = 0;
static BGA* bga = 0;

int OpenBmson(String filePath) {
	CloseBmson();
	ResetTmp();
	bmson = new Bmson;
	version = new DynamicArrayChar;
	info = new BmsonInfo;
	lines = new DynamicArray_BarLine;
	bpm_events = new DynamicArray_BpmEvent;
	stop_events = new DynamicArray_StopEvent;
	sound_channels = new DynamicArray_SoundChannel;
	bga = new BGA;

	char buf[1024];

	ifstream ifs(filePath->GetValue());
	IStreamWrapper isw(ifs);
	bmdoc.ParseStream(isw);

	/*----- ----- ----- ----- ----- ----- ----- version ----- ----- ----- ----- ----- ----- -----*/
	if (!bmdoc.HasMember(KEY_VERSION)) {
		printfDx("%s is not found.\n", KEY_VERSION);
		return -1;
	}
	if (!bmdoc[KEY_VERSION].IsString()) {
		printfDx("%s is invalid.\n", KEY_VERSION);
		return -1;
	}
	version->SetValues((char*)bmdoc[KEY_VERSION].GetString(), strlen(bmdoc[KEY_VERSION].GetString()));

	/*----- ----- ----- ----- ----- ----- ----- info ----- ----- ----- ----- ----- ----- -----*/
	if (!bmdoc.HasMember(KEY_INFO)) {
		printfDx("%s is not found.\n", KEY_INFO);
		return -1;
	}

	ResetTmps();
	if (bmdoc[KEY_INFO].HasMember(KEY_INFO_TITLE)) {
		if (!bmdoc[KEY_INFO][KEY_INFO_TITLE].IsString()) {
			printfDx("%s in %s is invalid.\n", KEY_INFO_TITLE, KEY_INFO);
			return -1;
		}
		tmps->SetValues((char*)bmdoc[KEY_INFO][KEY_INFO_TITLE].GetString(), strlen(bmdoc[KEY_INFO][KEY_INFO_TITLE].GetString()));
	}
	info->SetTitle(tmps);

	ResetTmps();
	if (bmdoc[KEY_INFO].HasMember(KEY_INFO_SUBTITLE)) {
		if (!bmdoc[KEY_INFO][KEY_INFO_SUBTITLE].IsNull()) {
			if (!bmdoc[KEY_INFO][KEY_INFO_SUBTITLE].IsString()) {
				printfDx("%s in %s is invalid.\n", KEY_INFO_SUBTITLE, KEY_INFO);
				return -1;
			} else {
				tmps->SetValues((char*)bmdoc[KEY_INFO][KEY_INFO_SUBTITLE].GetString(), strlen(bmdoc[KEY_INFO][KEY_INFO_SUBTITLE].GetString()));
				info->SetSubtitle(tmps);
			}
		}
	}
	info->SetSubtitle(tmps);

	ResetTmps();
	if (bmdoc[KEY_INFO].HasMember(KEY_INFO_ARTIST)) {
		if (!bmdoc[KEY_INFO][KEY_INFO_ARTIST].IsString()) {
			printfDx("%s in %s is invalid.\n", KEY_INFO_ARTIST, KEY_INFO);
			return -1;
		}
		tmps->SetValues((char*)bmdoc[KEY_INFO][KEY_INFO_ARTIST].GetString(), strlen(bmdoc[KEY_INFO][KEY_INFO_ARTIST].GetString()));
	}
	info->SetArtist(tmps);

	ResetTmps();
	if (bmdoc[KEY_INFO].HasMember(KEY_INFO_SUBARTISTS)) {
		if (!bmdoc[KEY_INFO][KEY_INFO_SUBARTISTS].IsNull()) {
			if (!bmdoc[KEY_INFO][KEY_INFO_SUBARTISTS].IsArray()) {
				printfDx("%s in %s is invalid.\n", KEY_INFO_SUBARTISTS, KEY_INFO);
				return -1;
			} else {
				for (int i = 0; i < bmdoc[KEY_INFO][KEY_INFO_SUBARTISTS].Size(); i++) {
					ResetTmps();
					if (!bmdoc[KEY_INFO][KEY_INFO_SUBARTISTS][i].IsString()) {
						printfDx("%s[%d] in %s is invalid.\n", KEY_INFO_SUBARTISTS, i, KEY_INFO);
						return -1;
					}
					tmps->SetValues((char*)bmdoc[KEY_INFO][KEY_INFO_SUBARTISTS][i].GetString(), strlen(bmdoc[KEY_INFO][KEY_INFO_SUBARTISTS][i].GetString()));
					info->AddSubartist(tmps);
				}
			}
		}
	}
	info->AddSubartist(tmps);

	ResetTmps();
	if (bmdoc[KEY_INFO].HasMember(KEY_INFO_GENRE)) {
		if (!bmdoc[KEY_INFO][KEY_INFO_GENRE].IsString()) {
			printfDx("%s in %s is invalid.\n", KEY_INFO_GENRE, KEY_INFO);
			return -1;
		}
		tmps->SetValues((char*)bmdoc[KEY_INFO][KEY_INFO_GENRE].GetString(), strlen(bmdoc[KEY_INFO][KEY_INFO_GENRE].GetString()));
	}
	info->SetGenre(tmps);

	ResetTmps();
	tmps->SetValues(DEFAULT_MODEHINT, strlen(DEFAULT_MODEHINT));
	if (bmdoc[KEY_INFO].HasMember(KEY_INFO_MODEHINT)) {
		if (!bmdoc[KEY_INFO][KEY_INFO_MODEHINT].IsNull()) {
			if (!bmdoc[KEY_INFO][KEY_INFO_MODEHINT].IsString()) {
				printfDx("%s in %s is invalid.\n", KEY_INFO_MODEHINT, KEY_INFO);
				return -1;
			} else {
				tmps->SetValues((char*)bmdoc[KEY_INFO][KEY_INFO_MODEHINT].GetString(), strlen(bmdoc[KEY_INFO][KEY_INFO_MODEHINT].GetString()));
				info->SetModeHint(tmps);
			}
		}
	}
	info->SetModeHint(tmps);

	ResetTmps();
	if (bmdoc[KEY_INFO].HasMember(KEY_INFO_CHARTNAME)) {
		if (!bmdoc[KEY_INFO][KEY_INFO_CHARTNAME].IsString()) {
			printfDx("%s in %s is invalid.\n", KEY_INFO_CHARTNAME, KEY_INFO);
			return -1;
		}
		tmps->SetValues((char*)bmdoc[KEY_INFO][KEY_INFO_CHARTNAME].GetString(), strlen(bmdoc[KEY_INFO][KEY_INFO_CHARTNAME].GetString()));
	}
	info->SetChartName(tmps);

	info->SetLevel(DEFAULT_LEVEL);
	if (bmdoc[KEY_INFO].HasMember(KEY_INFO_LEVEL)) {
		if (!bmdoc[KEY_INFO][KEY_INFO_LEVEL].IsUint64()) {
			printfDx("%s in %s is invalid.\n", KEY_INFO_LEVEL, KEY_INFO);
			return -1;
		}
		info->SetLevel(bmdoc[KEY_INFO][KEY_INFO_LEVEL].GetUint64());
	}

	info->SetInitBpm(DEFAULT_INITBPM);
	if (bmdoc[KEY_INFO].HasMember(KEY_INFO_INITBPM)) {
		if (bmdoc[KEY_INFO][KEY_INFO_INITBPM].IsDouble()) {
			info->SetInitBpm(bmdoc[KEY_INFO][KEY_INFO_INITBPM].GetDouble());
		} else {
			if (bmdoc[KEY_INFO][KEY_INFO_INITBPM].IsInt()) {
				info->SetInitBpm((double)bmdoc[KEY_INFO][KEY_INFO_INITBPM].GetInt());
			} else {
				printfDx("%s in %s is invalid.\n", KEY_INFO_INITBPM, KEY_INFO);
				return -1;
			}
		}
	}

	info->SetJudgeRank(DEFAULT_JUDGERANK);
	if (bmdoc[KEY_INFO].HasMember(KEY_INFO_JUDGERANK)) {
		if (!bmdoc[KEY_INFO][KEY_INFO_JUDGERANK].IsNull()) {
			if (bmdoc[KEY_INFO][KEY_INFO_JUDGERANK].IsDouble()) {
				info->SetJudgeRank(bmdoc[KEY_INFO][KEY_INFO_JUDGERANK].GetDouble());
			} else {
				if (bmdoc[KEY_INFO][KEY_INFO_JUDGERANK].IsInt()) {
					info->SetJudgeRank((double)bmdoc[KEY_INFO][KEY_INFO_JUDGERANK].GetInt());
				} else {
					printfDx("%s in %s is invalid.\n", KEY_INFO_JUDGERANK, KEY_INFO);
					return -1;
				}
			}
		}
	}

	info->SetTotal(DEFAULT_TOTAL);
	if (bmdoc[KEY_INFO].HasMember(KEY_INFO_TOTAL)) {
		if (!bmdoc[KEY_INFO][KEY_INFO_TOTAL].IsNull()) {
			if (bmdoc[KEY_INFO][KEY_INFO_TOTAL].IsDouble()) {
				info->SetTotal(bmdoc[KEY_INFO][KEY_INFO_TOTAL].GetDouble());
			} else {
				if (bmdoc[KEY_INFO][KEY_INFO_TOTAL].IsInt()) {
					info->SetTotal(bmdoc[KEY_INFO][KEY_INFO_TOTAL].GetDouble());
				} else {
					printfDx("%s in %s is invalid.\n", KEY_INFO_TOTAL, KEY_INFO);
					return -1;
				}
			}
		}
	}

	ResetTmps();
	if (bmdoc[KEY_INFO].HasMember(KEY_INFO_BACKIMAGE)) {
		if (!bmdoc[KEY_INFO][KEY_INFO_BACKIMAGE].IsNull()) {
			if (!bmdoc[KEY_INFO][KEY_INFO_BACKIMAGE].IsString()) {
				printfDx("%s in %s is invalid.\n", KEY_INFO_BACKIMAGE, KEY_INFO);
				return -1;
			} else {
				tmps->SetValues((char*)bmdoc[KEY_INFO][KEY_INFO_BACKIMAGE].GetString(), strlen(bmdoc[KEY_INFO][KEY_INFO_BACKIMAGE].GetString()));
				info->SetBackImage(tmps);
			}
		}
	}
	info->SetBackImage(tmps);

	ResetTmps();
	if (bmdoc[KEY_INFO].HasMember(KEY_INFO_EYECATCHIMAGE)) {
		if (!bmdoc[KEY_INFO][KEY_INFO_EYECATCHIMAGE].IsNull()) {
			if (!bmdoc[KEY_INFO][KEY_INFO_EYECATCHIMAGE].IsString()) {
				printfDx("%s in %s is invalid.\n", KEY_INFO_EYECATCHIMAGE, KEY_INFO);
				return -1;
			} else {
				tmps->SetValues((char*)bmdoc[KEY_INFO][KEY_INFO_EYECATCHIMAGE].GetString(), strlen(bmdoc[KEY_INFO][KEY_INFO_EYECATCHIMAGE].GetString()));
				info->SetEyecatchImage(tmps);
			}
		}
	}
	info->SetEyecatchImage(tmps);

	ResetTmps();
	if (bmdoc[KEY_INFO].HasMember(KEY_INFO_BANNERIMAGE)) {
		if (!bmdoc[KEY_INFO][KEY_INFO_BANNERIMAGE].IsNull()) {
			if (!bmdoc[KEY_INFO][KEY_INFO_BANNERIMAGE].IsString()) {
				printfDx("%s in %s is invalid.\n", KEY_INFO_BANNERIMAGE, KEY_INFO);
				return -1;
			} else {
				tmps->SetValues((char*)bmdoc[KEY_INFO][KEY_INFO_BANNERIMAGE].GetString(), strlen(bmdoc[KEY_INFO][KEY_INFO_BANNERIMAGE].GetString()));
				info->SetBannerImage(tmps);
			}
		}
	}
	info->SetBannerImage(tmps);

	info->SetResolution(DEFAULT_RESOLUTION);
	if (bmdoc[KEY_INFO].HasMember(KEY_INFO_RESOLUTION)) {
		if (!bmdoc[KEY_INFO][KEY_INFO_RESOLUTION].IsNull()) {
			if (!bmdoc[KEY_INFO][KEY_INFO_RESOLUTION].IsUint64()) {
				printfDx("%s in %s is invalid.\n", KEY_INFO_RESOLUTION, KEY_INFO);
				return -1;
			}
			info->SetResolution(bmdoc[KEY_INFO][KEY_INFO_RESOLUTION].GetUint64());
		}
	}

	/*----- ----- ----- ----- ----- ----- ----- lines ----- ----- ----- ----- ----- ----- -----*/
	if (!bmdoc.HasMember(KEY_LINES)) {
		printfDx("%s is not found.\n", KEY_LINES);
		return -1;
	}
	if (!bmdoc[KEY_LINES].IsArray()) {
		printfDx("%s is invalid.\n", KEY_LINES);
		return -1;
	}
	for (int i = 0; i < bmdoc[KEY_LINES].Size(); i++) {
		ResetTmpbl();
		if (!bmdoc[KEY_LINES][i].HasMember(KEY_LINES_Y)) {
			printfDx("%s in %s[%d] is not found.\n", KEY_LINES_Y, KEY_LINES, i);
			return -1;
		}
		if (!bmdoc[KEY_LINES][i][KEY_LINES_Y].IsUint64()) {
			printfDx("%s in %s[%d] is invalid.\n", KEY_LINES_Y, KEY_LINES, i);
			return -1;
		}
		tmpbl->SetY(bmdoc[KEY_LINES][i][KEY_LINES_Y].GetUint64());
		lines->AddValue(*tmpbl);
	}

	/*----- ----- ----- ----- ----- ----- ----- bpm_events ----- ----- ----- ----- ----- ----- -----*/
	if (bmdoc.HasMember(KEY_BPMEVENTS)) {
		if (!bmdoc[KEY_BPMEVENTS].IsArray()) {
			printfDx("%s is invalid.\n", KEY_BPMEVENTS);
			return -1;
		}
		for (int i = 0; i < bmdoc[KEY_BPMEVENTS].Size(); i++) {
			ResetTmpbe();
			if (!bmdoc[KEY_BPMEVENTS][i].HasMember(KEY_BPMEVENTS_Y)) {
				printfDx("%s in %s[%d] is not found.\n", KEY_BPMEVENTS_Y, KEY_BPMEVENTS, i);
				return -1;
			} else {
				if (!bmdoc[KEY_BPMEVENTS][i][KEY_BPMEVENTS_Y].IsUint64()) {
					printfDx("%s in %s[%d] is invalid.\n", KEY_BPMEVENTS_Y, KEY_BPMEVENTS, i);
					return -1;
				}
				tmpbe->SetY(bmdoc[KEY_BPMEVENTS][i][KEY_BPMEVENTS_Y].GetUint64());
			}
			if (!bmdoc[KEY_BPMEVENTS][i].HasMember(KEY_BPMEVENTS_BPM)) {
				printfDx("%s in %s[%d] is not found.\n", KEY_BPMEVENTS_BPM, KEY_BPMEVENTS, i);
			} else {
				if (!bmdoc[KEY_BPMEVENTS][i][KEY_BPMEVENTS_BPM].IsDouble()) {
					if (!bmdoc[KEY_BPMEVENTS][i][KEY_BPMEVENTS_BPM].IsInt()) {
						printfDx("%s in %s[%d] is invalid.\n", KEY_BPMEVENTS_BPM, KEY_BPMEVENTS, i);
						return -1;
					} else {
						tmpbe->SetBpm((double)bmdoc[KEY_BPMEVENTS][i][KEY_BPMEVENTS_BPM].GetInt());
					}
				} else {
					tmpbe->SetBpm(bmdoc[KEY_BPMEVENTS][i][KEY_BPMEVENTS_BPM].GetDouble());
				}
			}
			bpm_events->AddValue(*tmpbe);
		}
	}

	/*----- ----- ----- ----- ----- ----- ----- stop_events ----- ----- ----- ----- ----- ----- -----*/
	if (bmdoc.HasMember(KEY_STOPEVENTS)) {
		if (!bmdoc[KEY_STOPEVENTS].IsArray()) {
			printfDx("%s is invalid.\n", KEY_STOPEVENTS);
			return -1;
		}
		for (int i = 0; i < bmdoc[KEY_STOPEVENTS].Size(); i++) {
			ResetTmpse();
			if (!bmdoc[KEY_STOPEVENTS][i].HasMember(KEY_STOPEVENTS_Y)) {
				printfDx("%s in %s[%d] is not found.\n", KEY_STOPEVENTS_Y, KEY_STOPEVENTS, i);
				return -1;
			}
			if (!bmdoc[KEY_STOPEVENTS][i][KEY_STOPEVENTS_Y].IsUint64()) {
				printfDx("%s in %s[%d] is invalid.\n", KEY_STOPEVENTS_Y, KEY_STOPEVENTS, i);
				return -1;
			}
			tmpse->SetY(bmdoc[KEY_STOPEVENTS][i][KEY_STOPEVENTS_Y].GetUint64());

			if (!bmdoc[KEY_STOPEVENTS][i].HasMember(KEY_STOPEVENTS_DURATION)) {
				printfDx("%s in %s[%d] is not found.\n", KEY_STOPEVENTS_DURATION, KEY_STOPEVENTS, i);
				return -1;
			}
			if (!bmdoc[KEY_STOPEVENTS][i][KEY_STOPEVENTS_DURATION].IsUint64()) {
				printfDx("%s in %s[%d] is invalid.\n", KEY_STOPEVENTS_DURATION, KEY_STOPEVENTS, i);
				return -1;
			}
			tmpse->SetY(bmdoc[KEY_STOPEVENTS][i][KEY_STOPEVENTS_DURATION].GetUint64());
			stop_events->AddValue(*tmpse);
		}
	}

	/*----- ----- ----- ----- ----- ----- ----- sound_channels ----- ----- ----- ----- ----- ----- -----*/
	if (!bmdoc.HasMember(KEY_SOUNDCHANNELS)) {
		printfDx("%s is not found.\n", KEY_SOUNDCHANNELS);
		return -1;
	}
	if (!bmdoc[KEY_SOUNDCHANNELS].IsArray()) {
		printfDx("%s is invalid.\n", KEY_SOUNDCHANNELS);
		return -1;
	}
	for (int i = 0; i < bmdoc[KEY_SOUNDCHANNELS].Size(); i++) {
		ResetTmps();
		ResetTmpns();
		ResetTmpsc();
		if (!bmdoc[KEY_SOUNDCHANNELS][i].HasMember(KEY_SOUNDCHANNELS_NAME)) {
			printfDx("%s in %s[%d] is not found.\n", KEY_SOUNDCHANNELS_NAME, KEY_SOUNDCHANNELS, i);
			return -1;
		}
		if (!bmdoc[KEY_SOUNDCHANNELS][i][KEY_SOUNDCHANNELS_NAME].IsString()) {
			printfDx("%s in %s[%d] is invalid.\n", KEY_SOUNDCHANNELS_NAME, KEY_SOUNDCHANNELS, i);
			return -1;
		}
		tmps->SetValues((char*)bmdoc[KEY_SOUNDCHANNELS][i][KEY_SOUNDCHANNELS_NAME].GetString(), strlen(bmdoc[KEY_SOUNDCHANNELS][i][KEY_SOUNDCHANNELS_NAME].GetString()));
		tmpsc->SetName(tmps);

		if (!bmdoc[KEY_SOUNDCHANNELS][i].HasMember(KEY_SOUNDCHANNELS_NOTES)) {
			printfDx("%s in %s[%d] is not found.\n", KEY_SOUNDCHANNELS_NOTES, KEY_SOUNDCHANNELS, i);
			return -1;
		}
		if (!bmdoc[KEY_SOUNDCHANNELS][i][KEY_SOUNDCHANNELS_NOTES].IsArray()) {
			printfDx("%s in %s[%d] is invalid.\n", KEY_SOUNDCHANNELS_NOTES, KEY_SOUNDCHANNELS, i);
			return -1;
		}
		for (int j = 0; j < bmdoc[KEY_SOUNDCHANNELS][i][KEY_SOUNDCHANNELS_NOTES].Size(); j++) {
			ResetTmpn();
			if (!bmdoc[KEY_SOUNDCHANNELS][i][KEY_SOUNDCHANNELS_NOTES][j].HasMember(KEY_SOUNDCHANNELS_NOTES_X)) {
				printfDx("%s in %s[%d] in %s[%d] is not found.\n", KEY_SOUNDCHANNELS_NOTES_X, KEY_SOUNDCHANNELS_NOTES, j, KEY_SOUNDCHANNELS, i);
				return -1;
			}
			if (!bmdoc[KEY_SOUNDCHANNELS][i][KEY_SOUNDCHANNELS_NOTES][j].HasMember(KEY_SOUNDCHANNELS_NOTES_Y)) {
				printfDx("%s in %s[%d] in %s[%d] is not found.\n", KEY_SOUNDCHANNELS_NOTES_Y, KEY_SOUNDCHANNELS_NOTES, j, KEY_SOUNDCHANNELS, i);
				return -1;
			}
			if (!bmdoc[KEY_SOUNDCHANNELS][i][KEY_SOUNDCHANNELS_NOTES][j].HasMember(KEY_SOUNDCHANNELS_NOTES_L)) {
				printfDx("%s in %s[%d] in %s[%d] is not found.\n", KEY_SOUNDCHANNELS_NOTES_L, KEY_SOUNDCHANNELS_NOTES, j, KEY_SOUNDCHANNELS, i);
				return -1;
			}
			if (!bmdoc[KEY_SOUNDCHANNELS][i][KEY_SOUNDCHANNELS_NOTES][j].HasMember(KEY_SOUNDCHANNELS_NOTES_C)) {
				printfDx("%s in %s[%d] in %s[%d] is not found.\n", KEY_SOUNDCHANNELS_NOTES_C, KEY_SOUNDCHANNELS_NOTES, j, KEY_SOUNDCHANNELS, i);
				return -1;
			}

			if (!bmdoc[KEY_SOUNDCHANNELS][i][KEY_SOUNDCHANNELS_NOTES][j][KEY_SOUNDCHANNELS_NOTES_X].IsInt()) {
				printfDx("%s in %s[%d] in %s[%d] is invalid.\n", KEY_SOUNDCHANNELS_NOTES_X, KEY_SOUNDCHANNELS_NOTES, j, KEY_SOUNDCHANNELS, i);
				return -1;
			}
			if (!bmdoc[KEY_SOUNDCHANNELS][i][KEY_SOUNDCHANNELS_NOTES][j][KEY_SOUNDCHANNELS_NOTES_Y].IsUint64()) {
				printfDx("%s in %s[%d] in %s[%d] is invalid.\n", KEY_SOUNDCHANNELS_NOTES_Y, KEY_SOUNDCHANNELS_NOTES, j, KEY_SOUNDCHANNELS, i);
				return -1;
			}
			if (!bmdoc[KEY_SOUNDCHANNELS][i][KEY_SOUNDCHANNELS_NOTES][j][KEY_SOUNDCHANNELS_NOTES_L].IsUint64()) {
				printfDx("%s in %s[%d] in %s[%d] is invalid.\n", KEY_SOUNDCHANNELS_NOTES_L, KEY_SOUNDCHANNELS_NOTES, j, KEY_SOUNDCHANNELS, i);
				return -1;
			}
			if (!bmdoc[KEY_SOUNDCHANNELS][i][KEY_SOUNDCHANNELS_NOTES][j][KEY_SOUNDCHANNELS_NOTES_C].IsBool()) {
				printfDx("%s in %s[%d] in %s[%d] is invalid.\n",KEY_SOUNDCHANNELS_NOTES_C, KEY_SOUNDCHANNELS_NOTES, j, KEY_SOUNDCHANNELS, i);
				return -1;
			}
			tmpn->SetX(bmdoc[KEY_SOUNDCHANNELS][i][KEY_SOUNDCHANNELS_NOTES][j][KEY_SOUNDCHANNELS_NOTES_X].GetInt());
			tmpn->SetY(bmdoc[KEY_SOUNDCHANNELS][i][KEY_SOUNDCHANNELS_NOTES][j][KEY_SOUNDCHANNELS_NOTES_Y].GetUint64());
			tmpn->SetL(bmdoc[KEY_SOUNDCHANNELS][i][KEY_SOUNDCHANNELS_NOTES][j][KEY_SOUNDCHANNELS_NOTES_L].GetUint64());
			tmpn->SetC(bmdoc[KEY_SOUNDCHANNELS][i][KEY_SOUNDCHANNELS_NOTES][j][KEY_SOUNDCHANNELS_NOTES_C].GetBool());
			tmpns->AddValue(*tmpn);
		}
		tmpsc->SetNotes(tmpns);
		sound_channels->AddValue(*tmpsc);
		//‚±‚±‚Åtmpsc‚ª‹¶‚¤
	}

	/*----- ----- ----- ----- ----- ----- ----- BGA ----- ----- ----- ----- ----- ----- -----*/
	if (bmdoc.HasMember(KEY_BGA)) {
		if (bmdoc[KEY_BGA].HasMember(KEY_BGA_BGAHEADER)) {
			if (bmdoc[KEY_BGA][KEY_BGA_BGAHEADER].IsArray()) {
				ResetTmpbgahs();
				for (int i = 0; i < bmdoc[KEY_BGA][KEY_BGA_BGAHEADER].Size(); i++) {
					if (bmdoc[KEY_BGA][KEY_BGA_BGAHEADER][i].HasMember(KEY_BGA_BGAHEADER_ID)) {
						printfDx("%s in %s[%d] in %s is not found.\n", KEY_BGA_BGAHEADER_ID, KEY_BGA_BGAHEADER, i, KEY_BGA);
						return -1;
					}
					if (bmdoc[KEY_BGA][KEY_BGA_BGAHEADER][i].HasMember(KEY_BGA_BGAHEADER_NAME)) {
						printfDx("%s in %s[%d] in %s is not found.\n", KEY_BGA_BGAHEADER_NAME, KEY_BGA_BGAHEADER, i, KEY_BGA);
						return -1;
					}
					ResetTmps();
					ResetTmpbgah();
					if (!bmdoc[KEY_BGA][KEY_BGA_BGAHEADER][i][KEY_BGA_BGAHEADER_ID].IsUint64()) {
						printfDx("%s in %s[%d] in %s is invalid.\n", KEY_BGA_BGAHEADER_ID, KEY_BGA_BGAHEADER, i, KEY_BGA);
						return -1;
					}
					if (!bmdoc[KEY_BGA][KEY_BGA_BGAHEADER][i][KEY_BGA_BGAHEADER_NAME].IsString()) {
						printfDx("%s in %s[%d] in %s is invalid.\n", KEY_BGA_BGAHEADER_NAME, KEY_BGA_BGAHEADER, i, KEY_BGA);
						return -1;
					}
					tmpbgah->SetId(bmdoc[KEY_BGA][KEY_BGA_BGAHEADER][i][KEY_BGA_BGAHEADER_ID].GetUint64());
					tmps->SetValues((char*)bmdoc[KEY_BGA][KEY_BGA_BGAHEADER][i][KEY_BGA_BGAHEADER_NAME].GetString(), strlen(bmdoc[KEY_BGA][KEY_BGA_BGAHEADER][i][KEY_BGA_BGAHEADER_NAME].GetString()));
					tmpbgah->SetName(tmps);
					tmpbgahs->AddValue(*tmpbgah);
				}
				bga->SetBgaHeader(tmpbgahs);
			}
		}

		if (bmdoc[KEY_BGA].HasMember(KEY_BGA_BGAEVENTS)) {
			if (bmdoc[KEY_BGA][KEY_BGA_BGAEVENTS].IsArray()) {
				ResetTmpbgaes();
				for (int i = 0; i < bmdoc[KEY_BGA][KEY_BGA_BGAEVENTS].Size(); i++) {
					if (bmdoc[KEY_BGA][KEY_BGA_BGAHEADER][i].HasMember(KEY_BGA_BGAEVENTS_Y)) {
						printfDx("%s in %s[%d] in %s is not found.\n", KEY_BGA_BGAEVENTS_Y, KEY_BGA_BGAHEADER, i, KEY_BGA);
						return -1;
					}
					if (bmdoc[KEY_BGA][KEY_BGA_BGAHEADER][i].HasMember(KEY_BGA_BGAEVENTS_ID)) {
						printfDx("%s in %s[%d] in %s is not found.\n", KEY_BGA_BGAEVENTS_ID, KEY_BGA_BGAHEADER, i, KEY_BGA);
						return -1;
					}
					ResetTmps();
					ResetTmpbgae();
					if (!bmdoc[KEY_BGA][KEY_BGA_BGAEVENTS][i][KEY_BGA_BGAEVENTS_Y].IsUint64()) {
						printfDx("%s in %s[%d] in %s is invalid.\n", KEY_BGA_BGAEVENTS_Y, KEY_BGA_BGAEVENTS, i, KEY_BGA);
						return -1;
					}
					if (!bmdoc[KEY_BGA][KEY_BGA_BGAEVENTS][i][KEY_BGA_BGAEVENTS_ID].IsUint64()) {
						printfDx("%s in %s[%d] in %s is invalid.\n", KEY_BGA_BGAEVENTS_ID, KEY_BGA_BGAEVENTS, i, KEY_BGA);
						return -1;
					}
					tmpbgae->SetY(bmdoc[KEY_BGA][KEY_BGA_BGAEVENTS][i][KEY_BGA_BGAEVENTS_Y].GetUint64());
					tmpbgae->SetId(bmdoc[KEY_BGA][KEY_BGA_BGAEVENTS][i][KEY_BGA_BGAEVENTS_ID].GetUint64());
					tmpbgaes->AddValue(*tmpbgae);
				}
				bga->SetBgaEvents(tmpbgaes);
			}
		}

		if (bmdoc[KEY_BGA].HasMember(KEY_BGA_LAYEREVENTS)) {
			if (bmdoc[KEY_BGA][KEY_BGA_LAYEREVENTS].IsArray()) {
				ResetTmpbgaes();
				for (int i = 0; i < bmdoc[KEY_BGA][KEY_BGA_LAYEREVENTS].Size(); i++) {
					if (bmdoc[KEY_BGA][KEY_BGA_BGAHEADER][i].HasMember(KEY_BGA_LAYEREVENTS_Y)) {
						printfDx("%s in %s[%d] in %s is not found.\n", KEY_BGA_LAYEREVENTS_Y, KEY_BGA_BGAHEADER, i, KEY_BGA);
						return -1;
					}
					if (bmdoc[KEY_BGA][KEY_BGA_BGAHEADER][i].HasMember(KEY_BGA_LAYEREVENTS_ID)) {
						printfDx("%s in %s[%d] in %s is not found.\n", KEY_BGA_LAYEREVENTS_ID, KEY_BGA_BGAHEADER, i, KEY_BGA);
						return -1;
					}
					ResetTmps();
					ResetTmpbgae();
					if (!bmdoc[KEY_BGA][KEY_BGA_LAYEREVENTS][i][KEY_BGA_LAYEREVENTS_Y].IsUint64()) {
						printfDx("%s in %s[%d] in %s is invalid.\n", KEY_BGA_LAYEREVENTS_Y, KEY_BGA_LAYEREVENTS, i, KEY_BGA);
						return -1;
					}
					if (!bmdoc[KEY_BGA][KEY_BGA_LAYEREVENTS][i][KEY_BGA_LAYEREVENTS_ID].IsUint64()) {
						printfDx("%s in %s[%d] in %s is invalid.\n", KEY_BGA_LAYEREVENTS_ID, KEY_BGA_LAYEREVENTS, i, KEY_BGA);
						return -1;
					}
					tmpbgae->SetY(bmdoc[KEY_BGA][KEY_BGA_LAYEREVENTS][i][KEY_BGA_LAYEREVENTS_Y].GetUint64());
					tmpbgae->SetId(bmdoc[KEY_BGA][KEY_BGA_LAYEREVENTS][i][KEY_BGA_LAYEREVENTS_ID].GetUint64());
					tmpbgaes->AddValue(*tmpbgae);
				}
				bga->SetLayerEvents(tmpbgaes);
			}
		}

		if (bmdoc[KEY_BGA].HasMember(KEY_BGA_POOREVENTS)) {
			if (bmdoc[KEY_BGA][KEY_BGA_POOREVENTS].IsArray()) {
				ResetTmpbgaes();
				for (int i = 0; i < bmdoc[KEY_BGA][KEY_BGA_POOREVENTS].Size(); i++) {
					if (bmdoc[KEY_BGA][KEY_BGA_BGAHEADER][i].HasMember(KEY_BGA_POOREVENTS_Y)) {
						printfDx("%s in %s[%d] in %s is not found.\n", KEY_BGA_POOREVENTS_Y, KEY_BGA_BGAHEADER, i, KEY_BGA);
						return -1;
					}
					if (bmdoc[KEY_BGA][KEY_BGA_BGAHEADER][i].HasMember(KEY_BGA_POOREVENTS_ID)) {
						printfDx("%s in %s[%d] in %s is not found.\n", KEY_BGA_POOREVENTS_ID, KEY_BGA_BGAHEADER, i, KEY_BGA);
						return -1;
					}
					ResetTmps();
					ResetTmpbgae();
					if (!bmdoc[KEY_BGA][KEY_BGA_POOREVENTS][i][KEY_BGA_POOREVENTS_Y].IsUint64()) {
						printfDx("%s in %s[%d] in %s is invalid.\n", KEY_BGA_POOREVENTS_Y, KEY_BGA_POOREVENTS, i, KEY_BGA);
						return -1;
					}
					if (!bmdoc[KEY_BGA][KEY_BGA_POOREVENTS][i][KEY_BGA_POOREVENTS_ID].IsUint64()) {
						printfDx("%s in %s[%d] in %s is invalid.\n", KEY_BGA_POOREVENTS_ID, KEY_BGA_POOREVENTS, i, KEY_BGA);
						return -1;
					}
					tmpbgae->SetY(bmdoc[KEY_BGA][KEY_BGA_POOREVENTS][i][KEY_BGA_POOREVENTS_Y].GetUint64());
					tmpbgae->SetId(bmdoc[KEY_BGA][KEY_BGA_POOREVENTS][i][KEY_BGA_POOREVENTS_ID].GetUint64());
					tmpbgaes->AddValue(*tmpbgae);
				}
				bga->SetPoorEvents(tmpbgaes);
			}
		}
	}

	/*----- ----- ----- ----- ----- ----- ----- End ----- ----- ----- ----- ----- ----- -----*/

	bmson->SetVersion(version);
	bmson->SetInfo(info);
	bmson->SetLines(lines);
	bmson->SetBpmEvents(bpm_events);
	bmson->SetStopEvents(stop_events);
	bmson->SetSoundChannels(sound_channels);
	bmson->SetBga(bga);
	return 0;
}
void CloseBmson() {
	if (version != 0) {
		delete version;
		version = 0;
	}
	if (info != 0) {
		delete info;
		info = 0;
	}
	if (lines != 0) {
		delete lines;
		lines = 0;
	}
	if (bpm_events != 0) {
		delete bpm_events;
		bpm_events = 0;
	}
	if (stop_events != 0) {
		delete stop_events;
		stop_events = 0;
	}
	if (sound_channels != 0) {
		delete sound_channels;
		sound_channels = 0;
	}
	if (bga != 0) {
		delete bga;
		bga = 0;
	}
	if (tmps != 0) {
		delete tmps;
		tmps = 0;
	}
	if (tmpbl != 0) {
		delete tmpbl;
		tmpbl = 0;
	}
	if (tmpsc != 0) {
		delete tmpsc;
		tmpsc = 0;
	}
	if (tmpn != 0) {
		delete tmpn;
		tmpn = 0;
	}
	if (tmpbe != 0) {
		delete tmpbe;
		tmpbe = 0;
	}
	if (tmpse != 0) {
		delete tmpse;
		tmpse = 0;
	}
	if (tmpbgah != 0) {
		delete tmpbgah;
		tmpbgah = 0;
	}
	if (tmpbgae != 0) {
		delete tmpbgae;
		tmpbgae = 0;
	}
	if (tmpbgahs != 0) {
		delete tmpbgahs;
		tmpbgahs = 0;
	}
	if (tmpbgaes != 0) {
		delete tmpbgaes;
		tmpbgaes = 0;
	}
	if (bmson != 0) {
		delete bmson;
		bmson = 0;
	}
}

Bmson* GetBmson() {
	return bmson;
}
static void ResetTmp() {
	if (tmps != 0) { ResetTmps(); } else { tmps = new DynamicArrayChar; }
	if (tmpbl != 0) { ResetTmpbl(); } else { tmpbl = new BarLine; }
	if (tmpsc != 0) { ResetTmpsc(); } else { tmpsc = new SoundChannel; }
	if (tmpn != 0) { ResetTmpn(); } else { tmpn = new Note; }
	if (tmpns != 0) { ResetTmpns(); } else { tmpns = new DynamicArray_Note; }
	if (tmpbe != 0) { ResetTmpbe(); } else { tmpbe = new BpmEvent; }
	if (tmpse != 0) { ResetTmpse(); } else { tmpse = new StopEvent; }
	if (tmpbgah != 0) { ResetTmpbgah(); } else { tmpbgah = new BGAHeader; }
	if (tmpbgae != 0) { ResetTmpbgae(); } else { tmpbgae = new BGAEvent; }
	if (tmpbgahs != 0) { ResetTmpbgahs(); } else { tmpbgahs = new DynamicArray_BGAHeader; }
	if (tmpbgaes != 0) { ResetTmpbgaes(); } else { tmpbgaes = new DynamicArray_BGAEvent; }
}
static void ResetTmps() {
	delete tmps;
	tmps = new DynamicArrayChar;
}
static void ResetTmpbl() {
	delete tmpbl;
	tmpbl = new BarLine;
}
static void ResetTmpsc() {
	delete tmpsc;
	tmpsc = new SoundChannel;
}
static void ResetTmpn() {
	delete tmpn;
	tmpn = new Note;
}
static void ResetTmpns() {
	delete tmpns;
	tmpns = new DynamicArray_Note;
}
static void ResetTmpbe() {
	delete tmpbe;
	tmpbe = new BpmEvent;
}
static void ResetTmpse() {
	delete tmpse;
	tmpse = new StopEvent;
}
static void ResetTmpbgah() {
	delete tmpbgah;
	tmpbgah = new BGAHeader;
}
static void ResetTmpbgae() {
	delete tmpbgae;
	tmpbgae = new BGAEvent;
}
static void ResetTmpbgahs() {
	delete tmpbgahs;
	tmpbgahs = new DynamicArray_BGAHeader;
}
static void ResetTmpbgaes() {
	delete tmpbgaes;
	tmpbgaes = new DynamicArray_BGAEvent;
}

