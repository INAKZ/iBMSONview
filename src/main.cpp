#include "./util/util.h"
#include "./dxlibbmxutil.h"

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
	
	/*----- ������ -----*/
	char tmpStr[512];
	ZerosChar(tmpStr, 512);
	boolean acceptable = true;

	const unsigned int colorWhite = GetColor(255, 255, 255);

	/* ----- ----- ��������f�o�b�N�p ----- -----*/
	String bmxPath = new DynamicArrayChar;
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�������");
	/* ----- ----- �����܂Ńf�o�b�N�p ----- -----*/

	/*----- ----- ��������@MainLoop ----- -----*/
	while (ProcessMessage() == 0 && !gameEnd) {
		if (GetDragFilePath(tmpStr) == 0 && acceptable) {
			ClearDrawScreen();
			if (strlen(tmpStr) >= 510) {
				DrawFormatString(0, 0, GetColor(255, 255, 255), "Error:�t�@�C���p�X���������܂�");
			} else {
				bmxPath->SetValues(tmpStr, strlen(tmpStr));
				acceptable = false;
			}
		}
		if (!acceptable) {
			DrawFormatString(0, 0, GetColor(255, 255, 255), "��t: %s", bmxPath->GetValue());
			switch (WhatsThisBmx(bmxPath)) {
			case ID_BMXUTIL_BMSON:
				OpenBmson(bmxPath);
				DrawFormatString(0, 16, GetColor(255, 255, 255), "BMSON�t�@�C���ł�");
				break;
			case ID_BMXUTIL_BMS:
				DrawFormatString(0, 16, GetColor(255, 255, 255), "Error:BMS�t�@�C���͌��ݖ��Ή��ł������̂����Ή��\��ł�");
				break;
			case ID_BMXUTIL_ERROR:
				DrawFormatString(0, 16, GetColor(255, 255, 255), "Error:�Ή����Ă��Ȃ��t�@�C���`���܂��͒��̐l���m��Ȃ��t�@�C���`���ł�");
				break;
			default:
				DrawFormatString(0, 16, GetColor(255, 255, 255), "Error:���̂����Ή��\��̃t�@�C���`���ł�");
				break;
			}
			acceptable = true;
			delete bmxPath;
			bmxPath = new DynamicArrayChar;
			ZerosChar(tmpStr, 512);
		}

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) { gameEnd = true; }	//esc�L�[�ł��ł��I��
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
