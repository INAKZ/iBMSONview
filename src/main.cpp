#include "./util/util.h"
#include "./dxlibbmxutil.h"

extern boolean gameEnd = false;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	//ここでconfigを読み込む(画面サイズ、フルスクリーン、非同期読み込みとか)

	SetMainWindowText("iBMSONview");
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

	const unsigned int colorWhite = GetColor(255, 255, 255);

	/* ----- ----- ここからデバック用 ----- -----*/
	String bmxPath = new DynamicArrayChar;
	DrawFormatString(0, 0, GetColor(255, 255, 255), "初期状態");
	/* ----- ----- ここまでデバック用 ----- -----*/

	/*----- ----- ここから@MainLoop ----- -----*/
	while (ProcessMessage() == 0 && !gameEnd) {
		if (GetDragFilePath(tmpStr) == 0 && acceptable) {
			ClearDrawScreen();
			if (strlen(tmpStr) >= 510) {
				DrawFormatString(0, 0, GetColor(255, 255, 255), "Error:ファイルパスが長すぎます");
			} else {
				bmxPath->SetValues(tmpStr, strlen(tmpStr));
				acceptable = false;
			}
		}
		if (!acceptable) {
			DrawFormatString(0, 0, GetColor(255, 255, 255), "受付: %s", bmxPath->GetValue());
			switch (WhatsThisBmx(bmxPath)) {
			case ID_BMXUTIL_BMSON:
				OpenBmson(bmxPath);
				DrawFormatString(0, 16, GetColor(255, 255, 255), "BMSONファイルです");
				break;
			case ID_BMXUTIL_BMS:
				DrawFormatString(0, 16, GetColor(255, 255, 255), "Error:BMSファイルは現在未対応ですがそのうち対応予定です");
				break;
			case ID_BMXUTIL_ERROR:
				DrawFormatString(0, 16, GetColor(255, 255, 255), "Error:対応していないファイル形式または中の人が知らないファイル形式です");
				break;
			default:
				DrawFormatString(0, 16, GetColor(255, 255, 255), "Error:そのうち対応予定のファイル形式です");
				break;
			}
			acceptable = true;
			delete bmxPath;
			bmxPath = new DynamicArrayChar;
			ZerosChar(tmpStr, 512);
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
