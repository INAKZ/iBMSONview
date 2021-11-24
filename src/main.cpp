#include "./util/util.h"
#include "./dxlibbmxutil.h"
#include "./bmson/bmsonutil.h"

extern boolean gameEnd = false;

static constexpr char* KEY_NAME_WINDOW = (char*)"iBMSONview";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	//������config��ǂݍ���(��ʃT�C�Y�A�t���X�N���[���A�񓯊��ǂݍ��݂Ƃ�)

	SetMainWindowText(KEY_NAME_WINDOW);
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
	String bmxPath = new DynamicArrayChar;

	/* ----- ----- ��������f�o�b�N�p ----- -----*/
	printfDx("�������");
	/* ----- ----- �����܂Ńf�o�b�N�p ----- -----*/

	/*----- ----- ��������@MainLoop ----- -----*/
	while (ProcessMessage() == 0 && !gameEnd) {
		if (GetDragFilePath(tmpStr) == 0 && acceptable) {
			ClearDrawScreen();
			clsDx();
			if (strlen(tmpStr) >= 510) {
				printfDx("Error:�t�@�C���p�X���������܂�\n");
			} else {
				acceptable = false;
				delete bmxPath;
				bmxPath = new DynamicArrayChar;
				bmxPath->SetValues(tmpStr, strlen(tmpStr));
			}
		}
		if (!acceptable) {
			printfDx("��t: %s\n", bmxPath->GetValue());
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
				printfDx("Error:BMS�t�@�C���͌��ݖ��Ή��ł������̂����Ή��\��ł�\n");
				break;
			case ID_BMXUTIL_ERROR:
				printfDx("Error:�Ή����Ă��Ȃ��t�@�C���`���܂��͒��̐l���m��Ȃ��t�@�C���`���ł�\n");
				break;
			default:
				printfDx("Error:���̂����Ή��\��̃t�@�C���`���ł�\n");
				break;
			}
			ZerosChar(tmpStr, 512);
			acceptable = true;
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
