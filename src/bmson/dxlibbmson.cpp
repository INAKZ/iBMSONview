#include "dxlibbmson.h"

static Bmson bmson;
static int bmsonHandle;

void OpenBmson(String filePath) {
	InitGraph();
	InitSoundMem();
	String tmps = new DynamicArrayChar(1);
	int xx = 0;
	//String tmps2 = new DynamicArrayChar;

	bmsonHandle = FileRead_open(filePath->GetValue());
	for (int i = 0; FileRead_eof(bmsonHandle) == 0; i++) {
		tmps->SetValue(0, FileRead_getc(bmsonHandle));
		switch (tmps->GetValuen(0)) {
		case '"':
			tmps->DelValue(0);
			for (int j = 0; FileRead_eof(bmsonHandle) == 0; j++) {
				i++;
				tmps->AddValue(FileRead_getc(bmsonHandle));
				if (tmps->GetValuen(j) == '\\') {
					//タイトルとかに'"'が含まれる奴(\"とか)を摘発
					tmps->SetValue(j, FileRead_getc(bmsonHandle));
					i++;
					j--;
					continue;
				}
				if (tmps->GetValuen(j) == '"') {
					tmps->DelValue(j);
					break;
				}
			}
			if (strcmp(tmps->GetValue(), "version") == 0) {
				DrawFormatString(FINDMES_X, FINDMES_VER, GetColor(255, 255, 255), "%08d: version見つけたよ！", i);
				//bmson.SetVersion(tmps);
			}
			if (strcmp(tmps->GetValue(), "info") == 0) {
				DrawFormatString(FINDMES_X, FINDMES_INF + xx*40, GetColor(255, 255, 255), "%08d: info見つけたよ！", i);
				xx++;
			}
			if (strcmp(tmps->GetValue(), "lines") == 0) {
				DrawFormatString(FINDMES_X, FINDMES_LIN, GetColor(255, 255, 255), "%08d: lines見つけたよ！", i);
			}
			if (strcmp(tmps->GetValue(), "bpm_events") == 0) {
				DrawFormatString(FINDMES_X, FINDMES_BPS, GetColor(255, 255, 255), "%08d: bpm_events見つけたよ！", i);
			}
			if (strcmp(tmps->GetValue(), "stop_events") == 0) {
				DrawFormatString(FINDMES_X, FINDMES_STS, GetColor(255, 255, 255), "%08d: stop_events見つけたよ！", i);
			}
			if (strcmp(tmps->GetValue(), "sound_channels") == 0) {
				DrawFormatString(FINDMES_X, FINDMES_SCS, GetColor(255, 255, 255), "%08d: sound_channels見つけたよ！", i);
			}
			if (strcmp(tmps->GetValue(), "bga") == 0) {
				DrawFormatString(FINDMES_X, FINDMES_BGA, GetColor(255, 255, 255), "%08d: bga見つけたよ！", i);
			}
			delete tmps;
			tmps = new DynamicArrayChar(1);
			break;
		}
	}
	DrawFormatString(856, 0, GetColor(255, 255, 255), "読み込み終了");
	delete tmps;
	tmps = 0;
}

void CloseBmson() {
	bmson.~Bmson();
}