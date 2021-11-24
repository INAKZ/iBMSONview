#include "./util/util.h"
#include "./dxlibbmxutil.h"
#include "./bmson/bmsonutil.h"

extern boolean gameEnd = false;

static constexpr char* KEY_NAME_WINDOW = (char*)"iBMSONview";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	//ここでconfigを読み込む(画面サイズ、フルスクリーン、非同期読み込みとか)

	SetMainWindowText(KEY_NAME_WINDOW);
	ChangeWindowMode(TRUE);					//ウィンドウモード
	SetGraphMode(960, 480, 32);				//ウィンドウサイズ設定
	//SetOutApplicationLogValidFlag(FALSE);	//log.txtを作成しない
	if (DxLib_Init() == -1) { return -1; }	//DxLib初期化

	SetDrawScreen(DX_SCREEN_BACK);			//裏画面に描画
	SetAlwaysRunFlag(true);					// バックグラウンドでも動作を継続
	SetDragFileValidFlag(true);				// ファイルのD&Dを許可
	DragFileInfoClear();
	//SetUseASyncLoadFlag(TRUE);			// 非同期読み込みする(ローディングバーとか出せるし曲が止まらない)
	
	/*----- 初期化 -----*/
	char tmpStr[512];
	ZerosChar(tmpStr, 512);
	boolean acceptable = true;
	String bmxPath = new DynamicArrayChar;

	/* ----- ----- ここからデバック用 ----- -----*/
	printfDx("初期状態");
	/* ----- ----- ここまでデバック用 ----- -----*/

	/*----- ----- ここから@MainLoop ----- -----*/
	while (ProcessMessage() == 0 && !gameEnd) {
		if (GetDragFilePath(tmpStr) == 0 && acceptable) {
			ClearDrawScreen();
			clsDx();
			if (strlen(tmpStr) >= 510) {
				printfDx("Error:ファイルパスが長すぎます\n");
			} else {
				acceptable = false;
				delete bmxPath;
				bmxPath = new DynamicArrayChar;
				bmxPath->SetValues(tmpStr, strlen(tmpStr));
			}
		}
		if (!acceptable) {
			printfDx("受付: %s\n", bmxPath->GetValue());
			switch (WhatsThisBmx(bmxPath)) {
			case ID_BMXUTIL_BMSON:
				if (OpenBmson(bmxPath) == 0) {
					if (strcmp("1.0.0", GetBmson()->GetVersion()->GetValue()) == 0) {
						/*
						printfDx("acceptable version:%s\n", GetBmson()->GetVersion()->GetValue());
						printfDx("Info:\n");
						printfDx("L--:%s\n", GetBmson()->GetInfo()->GetTitle()->GetValue());
						printfDx("L--:%s\n", GetBmson()->GetInfo()->GetSubtitle()->GetValue());
						printfDx("L--:%s\n", GetBmson()->GetInfo()->GetArtist()->GetValue());
						printfDx("L--:%s\n", GetBmson()->GetInfo()->GetGenre()->GetValue());
						printfDx("L--:%s\n", GetBmson()->GetInfo()->GetModeHint()->GetValue());
						printfDx("L--:%s\n", GetBmson()->GetInfo()->GetChartName()->GetValue());
						printfDx("L--:%u\n", GetBmson()->GetInfo()->GetLevel());
						printfDx("L--:%f\n", GetBmson()->GetInfo()->GetInitBpm());
						printfDx("L--:%f\n", GetBmson()->GetInfo()->GetJudgeRank());
						printfDx("L--:%f\n", GetBmson()->GetInfo()->GetTotal());
						printfDx("L--:%s\n", GetBmson()->GetInfo()->GetBackImage()->GetValue());
						printfDx("L--:%s\n", GetBmson()->GetInfo()->GetEyecatchImage()->GetValue());
						printfDx("L--:%s\n", GetBmson()->GetInfo()->GetBannerImage()->GetValue());
						printfDx("L--:%s\n", GetBmson()->GetInfo()->GetPreviewMusic()->GetValue());
						printfDx("L--:%u\n", GetBmson()->GetInfo()->GetResolution());
						*/
						for (int i = 0; i < GetBmson()->GetLines()->GetSize(); i++) {
							printfDx("%03d:%lu\n", i, GetBmson()->GetLines()->GetValuen(i).GetY());
						}
					} else {
						printfDx("Error:unacceptable version\n");
					}
				} else {
					printfDx("Error:Invalid bmson\n");
				}
				break;
			case ID_BMXUTIL_BMS:
				printfDx("Error:BMSファイルは現在未対応ですがそのうち対応予定です\n");
				break;
			case ID_BMXUTIL_ERROR:
				printfDx("Error:対応していないファイル形式または中の人が知らないファイル形式です\n");
				break;
			default:
				printfDx("Error:そのうち対応予定のファイル形式です\n");
				break;
			}
			ZerosChar(tmpStr, 512);
			acceptable = true;
		}
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) { gameEnd = true; }	//escキーでいつでも終了
		ScreenFlip();
	}

	InitGraph();
	InitSoundMem();
	CloseBmson();
	delete bmxPath;
	bmxPath = 0;
	DxLib_End();
	return 0;
}
