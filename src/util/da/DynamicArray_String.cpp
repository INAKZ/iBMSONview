#include "DynamicArray_String.h"

DynamicArray_String::DynamicArray_String() {
	size = 0;
	value = new String[size];
	for (int i = 0; i < size; i++) {
		value[i] = new DynamicArrayChar;
	}
}
DynamicArray_String::DynamicArray_String(int setsize) {
	size = setsize;
	value = new String[size];
	for (int i = 0; i < size; i++) {
		value[i] = new DynamicArrayChar;
	}
}
DynamicArray_String::DynamicArray_String(String setvalue) {
	size = 1;
	value = new String[size];
	value[0]->SetValues(setvalue->GetValue(), setvalue->GetSize());
}
DynamicArray_String::~DynamicArray_String() {
	for (int i = 0; i < size; i++) {
		value[i]->~DynamicArrayChar();
	}
	delete[] value;
	value = 0;
}

void DynamicArray_String::Zeros() {
	for (int i = 0; i < size; i++) {
		value[i]->Zeros();
	}
}

int DynamicArray_String::GetSize() {
	return size;
}
String DynamicArray_String::GetValuen(int n) {
	return value[n];
}
String *DynamicArray_String::GetValue() {
	return value;
}

void DynamicArray_String::SetSize(int n) {
	size = n;
}
void DynamicArray_String::SetValue(int n, String v) {
	if (n > size) { return; }
	if (value[n]->GetValue() != 0) {
		delete value[n];
		value[n] = new DynamicArrayChar;
	}
	value[n]->SetValues(v->GetValue(), v->GetSize());
}
void DynamicArray_String::SetValues(String *array, int arraysize) {
	delete[] value;
	value = new String[arraysize];
	for (int i = 0; i < arraysize; i++) {
		value[i] = new DynamicArrayChar;
		SetValue(i, array[i]);
	}
	size = arraysize;
}

void DynamicArray_String::InsValues(int n, String *v, int vsize) {
	if (n > size) { return; }
	String *tmp;
	tmp = new String[size + vsize];
	for (int i = 0; i < n; i++) {
		tmp[i] = new DynamicArrayChar;
		tmp[i]->SetValues(value[i]->GetValue(), value[i]->GetSize());
	}
	for (int i = n; i < n + vsize; i++) {
		tmp[i] = new DynamicArrayChar;
		tmp[i]->SetValues(v[i - n]->GetValue(), v[i - n]->GetSize());
	}
	for (int i = n + vsize; i < size + vsize; i++) {
		tmp[i] = new DynamicArrayChar;
		tmp[i]->SetValues(value[i - vsize]->GetValue(), value[i - vsize]->GetSize());
	}
	delete[] value;
	value = tmp;
	size += vsize;
}
void DynamicArray_String::InsValue(int n, String v) {
	InsValues(n, &v, 1);
}
void DynamicArray_String::AddValues(String *v, int vsize) {
	InsValues(GetSize(), v, vsize);
}
void DynamicArray_String::AddValue(String v) {
	InsValues(GetSize(), &v, 1);
}
void DynamicArray_String::Cat(DynamicArray_String *src) {
	AddValues(src->GetValue(), src->GetSize());
}
void DynamicArray_String::DelValue(int n) {
	if (n >= size) { return; }
	String *tmp;
	tmp = new String[size - 1];
	for (int i = 0; i < n; i++) {
		tmp[i] = new DynamicArrayChar;
		tmp[i]->SetValues(value[i]->GetValue(), value[i]->GetSize());
	}
	for (int i = n + 1; i < size; i++) {
		tmp[i - 1] = new DynamicArrayChar;
		tmp[i - 1]->SetValues(value[i]->GetValue(), value[i]->GetSize());
	}
	delete[] value;
	value = tmp;
	size--;
}
