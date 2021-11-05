#include "BpmEvent.h"

BpmEvent::BpmEvent() {
	y = 0;
	bpm = 100;
}

unsigned long BpmEvent::GetY() {
	return y;
}
double BpmEvent::GetBpm() {
	return bpm;
}

void BpmEvent::SetY(unsigned long value) {
	y = value;
}
void BpmEvent::SetBpm(double value) {
	bpm = value;
}