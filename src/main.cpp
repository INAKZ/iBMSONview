
#include "./util/util.h"

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

	boolean acceptable = false;

	const unsigned int colorWhite = GetColor(255, 255, 255);
	//bmsMode = 1:bmson, 2:bmx, 3:なんか混ざってる, 0or-1:etc(error)

	/*----- 初期化 -----*/
	InitGraph();
	InitSoundMem();

	acceptable = true;

	/*----- ----- ここから@MainLoop ----- -----*/
	while (ProcessMessage() == 0 && !gameEnd) {

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) { gameEnd = true; }	//escキーでいつでも終了
		ScreenFlip();
	}

	InitGraph();
	InitSoundMem();
	DxLib_End();
	return 0;
}
