#include "DynamicArray_String.h"

DynamicArray_String::DynamicArray_String() {
	size = 1;
	value = new String[size];
}
DynamicArray_String::DynamicArray_String(int setsize) {
	size = setsize;
	value = new String[size];
}
DynamicArray_String::DynamicArray_String(String setvalue) {
	size = 1;
	value = new String[size];
	value[0] = setvalue;
}
DynamicArray_String::~DynamicArray_String() {
	delete[] value;
}

void DynamicArray_String::Zeros() {
	delete[] value;
	value = new String[size];
	/*for (int i = 0; i < size; i++) {
		value[i]->SetValues(new char[value[i]->GetSize()], value[i]->GetSize());
	}*/
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
	value[n] = v;
}
void DynamicArray_String::SetValues(String *array, int arraysize) {
	String *tmp;
	tmp = new String[arraysize];
	for (int i = 0; i < arraysize; i++) {
		tmp[i] = array[i];
	}
	delete[] value;
	value = tmp;
	size = arraysize;
}

void DynamicArray_String::InsValues(int n, String *v, int vsize) {
	String *tmp;
	if (n > size) { return; }
	tmp = new String[size + vsize];
	for (int i = 0; i < n; i++) {
		tmp[i] = value[i];
	}
	for (int i = n; i < n + vsize; i++) {
		tmp[i] = v[i - n];
	}
	for (int i = n + vsize; i < size + vsize; i++) {
		tmp[i] = value[i - vsize];
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
		tmp[i] = value[i];
	}
	for (int i = n + 1; i < size; i++) {
		tmp[i - 1] = value[i];
	}
	delete[] value;
	value = tmp;
	size--;
}
