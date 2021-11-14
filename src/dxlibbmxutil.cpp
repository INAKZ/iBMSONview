#include "dxlibbmxutil.h"

static int filetype;

int WhatsThisBmx(const String filePath) {
	filetype = ID_BMXUTIL_ZERO;
	char tmp;
	int size = filePath->GetSize();
	String tmps;
	tmps = new DynamicArrayChar;
	for (int i = 0; i < size; i++) {
		tmp = filePath->GetValuen(size - i);
		if (tmp == '.') { break; }
		tmps->InsValue(0, tmp);
	}
	if (strcmp(tmps->GetValue(), "bms") == 0 && filetype == ID_BMXUTIL_ZERO) {
		filetype = ID_BMXUTIL_BMS;
	}
	if (strcmp(tmps->GetValue(), "bme") == 0 && filetype == ID_BMXUTIL_ZERO) {
		filetype = ID_BMXUTIL_BME;
	}
	if (strcmp(tmps->GetValue(), "bml") == 0 && filetype == ID_BMXUTIL_ZERO) {
		filetype = ID_BMXUTIL_BML;
	}
	if (strcmp(tmps->GetValue(), "pms") == 0 && filetype == ID_BMXUTIL_ZERO) {
		filetype = ID_BMXUTIL_PMS;
	}
	if (strcmp(tmps->GetValue(), "bmson") == 0 && filetype == ID_BMXUTIL_ZERO) {
		filetype = ID_BMXUTIL_BMSON;
	}
	if (filetype == ID_BMXUTIL_ZERO) {
		filetype = ID_BMXUTIL_ERROR;
	}	
	return filetype;
}