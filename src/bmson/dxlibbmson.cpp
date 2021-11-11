#include "dxlibbmson.h"

static Bmson bmson;
static int bmsonHandle;

void OpenBmson(DAChar filePath) {
	String tmps = new DynamicArrayChar;
	String tmps2 = new DynamicArrayChar;

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
					tmps->DelValue(j);
					tmps->AddValue(FileRead_getc(bmsonHandle));
					i++;
					j--;
					continue;
				}
				if (tmps->GetValuen(j) == '"') {
					tmps->DelValue(j);
					break;
				}
			}
			if (tmps->GetValue() == "version") {
				DrawFormatString(0, 16, GetColor(255, 255, 255), "%d: version��������I", bmsonHandle);
				//bmson.SetVersion(tmps);
			}
			break;
		}
	}
}
