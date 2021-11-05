#include "StopEvent.h"

StopEvent::StopEvent() {
	y = 0;
	duration = 0;
}

unsigned long StopEvent::GetY() {
	return y;
}
unsigned long StopEvent::GetDuration() {
	return duration;
}

void StopEvent::SetY(unsigned long value) {
	y = value;
}
void StopEvent::SetDuration(unsigned long value) {
	duration = value;
}