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
DynamicArrayChar::DynamicArrayChar(int setsize, char* setvalue) {
	size = setsize;
	value = new char[size + 1];
	SetValues(setvalue, setsize);
}
DynamicArrayChar::~DynamicArrayChar() {
	delete[] value;
}

void DynamicArrayChar::Zeros() {
	ZerosChar(value, size + 1);
}

int DynamicArrayChar::GetSize() {
	return size;
}
char DynamicArrayChar::GetValuen(int n) {
	return value[n];
}
char *DynamicArrayChar::GetValue() {
	return value;
}

void DynamicArrayChar::SetSize(int n) {
	size = n;
}
void DynamicArrayChar::SetValue(int n, char v) {
	if (n > size) { return; }
	value[n] = v;
}
void DynamicArrayChar::SetValues(char *array, int arraysize) {
	char *tmp;
	tmp = new char[arraysize + 1];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	tmp[arraysize] = '\0';
	delete[] value;
	value = tmp;
	size = arraysize;
}

void DynamicArrayChar::InsValues(int n, char *v, int vsize) {
	if (n > size) { return; }
	char *tmp;
	tmp = new char[size + vsize + 1];
	for (int i = 0; i < n; i++) {
		tmp[i] = value[i];
	}
	for (int i = n; i < n + vsize; i++) {
		tmp[i] = v[i - n];
	}
	for (int i = n + vsize; i < size + vsize; i++) {
		tmp[i] = value[i - vsize];
	}
	tmp[size + vsize] = '\0';
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
	if (n >= size) { return; }
	char *tmp;
	tmp = new char[size];
	for (int i = 0; i < n; i++) {
		tmp[i] = value[i];
	}
	for (int i = n + 1; i < size; i++) {
		tmp[i - 1] = value[i];
	}
	tmp[size - 1] = '\0';
	delete[] value;
	value = tmp;
	size--;
}
