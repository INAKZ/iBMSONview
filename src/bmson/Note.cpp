#include "Note.h"

Note::Note() {
	x = 0;
	y = 0;
	l = 0;
	c = false;
}

int Note::GetX() {
	return x;
}
unsigned long Note::GetY() {
	return y;
}
unsigned long Note::GetL() {
	return l;
}
boolean Note::GetC() {
	return c;
}

void Note::SetX(int value) {
	x = value;
}
void Note::SetY(unsigned long value) {
	y = value;
}
void Note::SetL(unsigned long value) {
	l = value;
}
void Note::SetC(boolean value) {
	c = value;
}