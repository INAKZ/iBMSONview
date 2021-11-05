#include "BGA.h"

BGA::BGA() {
	bga_header = new DynamicArray_BGAHeader;
	bga_events = new DynamicArray_BGAEvent;
	layer_events = new DynamicArray_BGAEvent;
	poor_events = new DynamicArray_BGAEvent;
}
BGA::~BGA() {
	delete bga_header;
	delete bga_events;
	delete layer_events;
	delete poor_events;
}

DA_BGAHeader BGA::GetBgaHeader() {
	return bga_header;
}
DA_BGAEvent BGA::GetBgaEvents() {
	return bga_events;
}
DA_BGAEvent BGA::GetLayerEvents() {
	return layer_events;
}
DA_BGAEvent BGA::GetPoorEvents() {
	return poor_events;
}

void BGA::SetBgaHeader(DA_BGAHeader value) {
	bga_header->SetValues(value->GetValue(), value->GetSize());
}
void BGA::SetBgaEvents(DA_BGAEvent value) {
	bga_events->SetValues(value->GetValue(), value->GetSize());
}
void BGA::SetLayerEvents(DA_BGAEvent value) {
	layer_events->SetValues(value->GetValue(), value->GetSize());
}
void BGA::SetPoorEvents(DA_BGAEvent value) {
	poor_events->SetValues(value->GetValue(), value->GetSize());
}