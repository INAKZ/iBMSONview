#include "./util/util.h"
#include "./bmson/dxlibbmson.h"

extern boolean gameEnd = false;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	//������config��ǂݍ���(��ʃT�C�Y�A�t���X�N���[���A�񓯊��ǂݍ��݂Ƃ�)

	SetMainWindowText("iBMSONview");
	ChangeWindowMode(TRUE);					//�E�B���h�E���[�h
	SetGraphMode(960, 480, 32);				//�E�B���h�E�T�C�Y�ݒ�
	//SetOutApplicationLogValidFlag(FALSE);	//log.txt���쐬���Ȃ�
	if (DxLib_Init() == -1) { return -1; }	//DxLib������

	SetDrawScreen(DX_SCREEN_BACK);			//����ʂɕ`��
	SetAlwaysRunFlag(true);					// �o�b�N�O���E���h�ł�������p��
	SetDragFileValidFlag(true);				// �t�@�C����D&D������
	DragFileInfoClear();
	//SetUseASyncLoadFlag(TRUE);			// �񓯊��ǂݍ��݂���(���[�f�B���O�o�[�Ƃ��o���邵�Ȃ��~�܂�Ȃ�)

	//bmsMode = 1:bmson, 2:bmx, 3:�Ȃ񂩍������Ă�, 0or-1:etc(error)

	/*----- ������ -----*/
	boolean acceptable = true;
	char tmpPath[256];//256�����ȏ�̃p�X�͈����Ȃ��c�܊p���I�z��N���X��������̂ɂǂ��ɂ��Ȃ��̂��ȁH
	//boolean gameEnd = false;

	ZerosChar(tmpPath, 256);
	const unsigned int colorWhite = GetColor(255, 255, 255);

	/* ----- ----- ��������f�o�b�N�p ----- -----*/
	String bmxPath = new DynamicArrayChar;
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�������");
	/* ----- ----- �����܂Ńf�o�b�N�p ----- -----*/

	/*----- ----- ��������@MainLoop ----- -----*/
	while (ProcessMessage() == 0 && !gameEnd) {
		if (GetDragFilePath(tmpPath) == 0 && acceptable) {
			delete bmxPath;
			bmxPath = new DynamicArrayChar;
			for (int i = 0; tmpPath[i] != '\0'; i++) {
				bmxPath->AddValue(tmpPath[i]);
			}
			bmxPath->AddValue('\0');
			acceptable = false;
		}
		if (!acceptable) {
			InitGraph();
			InitSoundMem();
			ClearDrawScreen();
			DrawFormatString(0, 0, GetColor(255, 255, 255), "��t: %s", bmxPath->GetValue());
			acceptable = true;
			OpenBmson(bmxPath);
		}

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) { gameEnd = true; }	//esc�L�[�ł��ł��I��
		ScreenFlip();
	}

	InitGraph();
	InitSoundMem();
	delete bmxPath;
	DxLib_End();
	return 0;
}
