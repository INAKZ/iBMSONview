#include "ArrayUtil.h"

void ZerosShortInt(short int *array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}
}
void ZerosInt(int *array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}
}
void ZerosLongInt(long int *array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}
}
void ZerosLongLongInt(long long int *array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}
}
void ZerosUnsignedShortInt(unsigned short int *array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}
}
void ZerosUnsignedInt(unsigned int *array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}
}
void ZerosUnsignedLongInt(unsigned long int *array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}
}
void ZerosUnsignedLongLongInt(unsigned long long int *array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}
}
void ZerosFloat(float *array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}
}
void ZerosDouble(double *array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}
}
void ZerosChar(char *array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = '\0';
	}
}

void InitShortInt(short int *array, int size, short int value) {
	for (int i = 0; i < size; i++) {
		array[i] = value;
	}
}
void InitInt(int *array, int size, int value) {
	for (int i = 0; i < size; i++) {
		array[i] = value;
	}
}
void InitLongInt(long int *array, int size, long int value) {
	for (int i = 0; i < size; i++) {
		array[i] = value;
	}
}
void InitLongLongInt(long long int *array, int size, long long int value) {
	for (int i = 0; i < size; i++) {
		array[i] = value;
	}
}
void InitUnsignedShortInt(unsigned short int *array, int size, unsigned short int value) {
	for (int i = 0; i < size; i++) {
		array[i] = value;
	}
}
void InitUnsignedInt(unsigned int *array, int size, unsigned int value) {
	for (int i = 0; i < size; i++) {
		array[i] = value;
	}
}
void InitUnsignedLongInt(unsigned long int *array, int size, unsigned long int value) {
	for (int i = 0; i < size; i++) {
		array[i] = value;
	}
}
void InitUnsignedLongLongInt(unsigned long long int *array, int size, unsigned long long int value) {
	for (int i = 0; i < size; i++) {
		array[i] = value;
	}
}
void InitFloat(float *array, int size, float value) {
	for (int i = 0; i < size; i++) {
		array[i] = value;
	}
}
void InitDouble(double *array, int size, double value) {
	for (int i = 0; i < size; i++) {
		array[i] = value;
	}
}
void InitChar(char *array, int size, char value) {
	for (int i = 0; i < size; i++) {
		array[i] = value;
	}
}
void InitString(char *array, int size, char *value, int vsize) {
	strncpy_s(array, size, value, vsize);	
}