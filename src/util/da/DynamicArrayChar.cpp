#include "DynamicArrayChar.h"

//size:•¶Žš—ñ‚Ì’·‚³, value:•¶Žš—ñ+\0‚È‚Ì‚Å’·‚³‚Ísize+1
//value[size-1]‚Ü‚Å‚ª•¶Žš—ñ‚Åvalue[size]‚Íí‚É'\0'
DynamicArrayChar::DynamicArrayChar() {
	size = 0;
	value = new char[size + 1];
	Zeros();
}
DynamicArrayChar::DynamicArrayChar(int setsize) {
	size = setsize;
	value = new char[size + 1];
	Zeros();
}
DynamicArrayChar::DynamicArrayChar(char* setvalue) {
	size = strlen(setvalue);
	value = new char[size + 1];
	SetValues(setvalue, size);
}
DynamicArrayChar::DynamicArrayChar(int setsize, char* setvalue) {
	size = setsize;
	value = new char[size + 1];
	SetValues(setvalue, setsize);
}
DynamicArrayChar::~DynamicArrayChar() {
	delete[] value;
	value = 0;
}

void DynamicArrayChar::Zeros() {
	ZerosChar(value, size + 1);
}
void DynamicArrayChar::UpdateSize() {
	if (GetValuen(0) == '\0') { size = 0; return; }
	size = strlen(GetValue());
}

int DynamicArrayChar::GetSize() {
	UpdateSize();
	return size;
}
char DynamicArrayChar::GetValuen(int n) {
	if (n > size) { return '\0'; }
	return value[n];
}
char *DynamicArrayChar::GetValue() {
	return value;
}

void DynamicArrayChar::SetSize(int n) {
	size = n;
}
void DynamicArrayChar::SetValue(int n, char v) {
	UpdateSize();
	if (n > size) { return; }
	value[n] = v;
}
void DynamicArrayChar::SetValues(char *array, int arraysize) {
	delete[] value;
	value = new char[arraysize + 1];
	strncpy_s(value, arraysize + 1, array, arraysize);
	size = arraysize;
}

void DynamicArrayChar::InsValues(int n, char* v, int vsize) {
	UpdateSize();
	if (n > size) { return; }
	char* tmp;
	tmp = new char[size + vsize + 1];
	strncpy_s(tmp, size + vsize + 1, value, n);
	strcat_s(tmp, size + vsize + 1, v);
	if (n < size) {
		strcat_s(tmp, size + vsize + 1, value + n);
	}
	delete[] value;
	value = tmp;
	size += vsize;
}
void DynamicArrayChar::InsValue(int n, char v) {
	InsValues(n, &v, 1);
}
void DynamicArrayChar::AddValues(char *v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArrayChar::AddValue(char v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArrayChar::Cat(DynamicArrayChar *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArrayChar::DelValue(int n) {
	UpdateSize();
	if (n >= size) { return; }
	char *tmp;
	tmp = new char[size];
	strncpy_s(tmp, size, value, n);
	if (n + 1 < size) {
		strcat_s(tmp, size, value + (n + 1));
	}
	delete[] value;
	value = tmp;
	size--;
}
