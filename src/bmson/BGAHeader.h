#pragma once
#include "../util/util.h"

class BGAHeader {
public:
	BGAHeader();
	~BGAHeader();

	unsigned long GetId();
	DAChar GetName();

	void SetId(unsigned long value);
	void SetName(DAChar value);
	
private:
	unsigned long id;
	DAChar name;
};