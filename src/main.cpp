#include "./util/util.h"
#include "./bmson/dxlibbmson.h"

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

	//bmsMode = 1:bmson, 2:bmx, 3:なんか混ざってる, 0or-1:etc(error)

	/*----- 初期化 -----*/
	boolean acceptable = true;
	//boolean gameEnd = false;


	const unsigned int colorWhite = GetColor(255, 255, 255);

	/* ----- ----- ここからデバック用 ----- -----*/
	String bmxPath = new DynamicArrayChar;
	DrawFormatString(0, 0, GetColor(255, 255, 255), "初期状態");
	/* ----- ----- ここまでデバック用 ----- -----*/

	/*----- ----- ここから@MainLoop ----- -----*/
	while (ProcessMessage() == 0 && !gameEnd) {
		if (GetDragFilePath(bmxPath->GetValue()) == 0 && acceptable) {
			acceptable = false;
		}
		if (!acceptable) {
			InitGraph();
			InitSoundMem();
			ClearDrawScreen();
			DrawFormatString(0, 0, GetColor(255, 255, 255), "受付: %s", bmxPath->GetValue());
			DrawFormatString(0, 16, GetColor(255, 255, 255), "読み込み終わりー！");
			acceptable = true;
			OpenBmson(bmxPath);
		}

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) { gameEnd = true; }	//escキーでいつでも終了
		ScreenFlip();
	}

	InitGraph();
	InitSoundMem();
	delete bmxPath;
	DxLib_End();
	return 0;
}
