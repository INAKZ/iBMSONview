#include "BGAEvent.h"

BGAEvent::BGAEvent() {
	y = 0;
	id = 0;
}

unsigned long BGAEvent::GetY() {
	return y;
}
unsigned long BGAEvent::GetId() {
	return id;
}

void BGAEvent::SetY(unsigned long value) {
	y = value;
}
void BGAEvent::SetId(unsigned long value) {
	id = value;
}