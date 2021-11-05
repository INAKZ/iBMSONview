#pragma once
#include"DxLib.h"

void ZerosShortInt(short int *array, int size);
void ZerosInt(int *array, int size);
void ZerosLongInt(long int *array, int size);
void ZerosLongLongInt(long long int *array, int size);
void ZerosUnsignedShortInt(unsigned short int *array, int size);
void ZerosUnsignedInt(unsigned int *array, int size);
void ZerosUnsignedLongInt(unsigned long int *array, int size);
void ZerosUnsignedLongLongInt(unsigned long long int *array, int size);
void ZerosFloat(float *array, int size);
void ZerosDouble(double *array, int size);
void ZerosChar(char *array, int size);

void InitShortInt(short int *array, int size, short int value);
void InitInt(int *array, int size, int value);
void InitLongInt(long int *array, int size, long int value);
void InitLongLongInt(long long int *array, int size, long long int value);
void InitUnsignedShortInt(unsigned short int *array, int size, unsigned short int value);
void InitUnsignedInt(unsigned int *array, int size, unsigned int value);
void InitUnsignedLongInt(unsigned long int *array, int size, unsigned long int value);
void InitUnsignedLongLongInt(unsigned long long int *array, int size, unsigned long long int value);
void InitFloat(float *array, int size, float value);
void InitDouble(double *array, int size, double value);
void InitChar(char *array, int size, char value);
void InitString(char *array, int size, char *value, int vsize);