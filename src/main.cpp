
#include "./util/util.h"

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

	boolean acceptable = false;

	const unsigned int colorWhite = GetColor(255, 255, 255);
	//bmsMode = 1:bmson, 2:bmx, 3:�Ȃ񂩍������Ă�, 0or-1:etc(error)

	/*----- ������ -----*/
	InitGraph();
	InitSoundMem();

	acceptable = true;

	/*----- ----- ��������@MainLoop ----- -----*/
	while (ProcessMessage() == 0 && !gameEnd) {

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) { gameEnd = true; }	//esc�L�[�ł��ł��I��
		ScreenFlip();
	}

	InitGraph();
	InitSoundMem();
	DxLib_End();
	return 0;
}
