#include "BGAHeader.h"

BGAHeader::BGAHeader() {
	id = 0;
	name = new DynamicArrayChar;
}
BGAHeader::~BGAHeader() {
	delete name;
	name = 0;
}

unsigned long BGAHeader::GetId() {
	return id;
}
DAChar BGAHeader::GetName() {
	return name;
}

void BGAHeader::SetId(unsigned long value) {
	id = value;
}
void BGAHeader::SetName(DAChar value) {
	name->SetValues(value->GetValue(), value->GetSize());
}