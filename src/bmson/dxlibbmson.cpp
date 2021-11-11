#include "dxlibbmson.h"

static Bmson bmson;
static int bmsonHandle;

void OpenBmson(DAChar filePath) {
	String tmps = new DynamicArrayChar(1);
	//String tmps2 = new DynamicArrayChar;
	int xx = 0;

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
					//�^�C�g���Ƃ���'"'���܂܂��z(\"�Ƃ�)��E��
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
				DrawFormatString(0, 32 + 16*xx, GetColor(255, 255, 255), "%d: version��������I", i);
				xx++;
				//bmson.SetVersion(tmps);
			}
			tmps->Zeros();
			tmps->SetSize(1);
			break;
		}
	}
	DrawFormatString(0, 16, GetColor(255, 255, 255), "�ǂݍ��ݏI��");
}
