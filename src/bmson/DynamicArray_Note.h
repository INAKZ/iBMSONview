#pragma once
#include "../util/util.h"
#include "Note.h"

class DynamicArray_Note {
public:
	DynamicArray_Note();
	DynamicArray_Note(int setsize);
	~DynamicArray_Note();

	void Zeros();

	int GetSize();
	Note GetValuen(int n);
	Note* GetValue();

	void SetValue(int n, Note v);
	void SetValues(Note* array, int arraysize);

	void InsValues(int n, Note* v, int vsize);
	void InsValue(int n, Note v);
	void AddValues(Note* v, int vsize);
	void AddValue(Note v);
	void Cat(DynamicArray_Note *src);
	void DelValue(int n);

private:
	int size;
	Note* value;
};
typedef DynamicArray_Note* DA_Note;