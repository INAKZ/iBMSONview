#pragma once
#include "../util/util.h"
#include "BGAHeader.h"
#include "BGAEvent.h"
#include "DynamicArray_BGAHeader.h"
#include "DynamicArray_BGAEvent.h"

class BGA {
public:
	BGA();
	~BGA();

	void Zeros();

	DA_BGAHeader GetBgaHeader();
	DA_BGAEvent GetBgaEvents();
	DA_BGAEvent GetLayerEvents();
	DA_BGAEvent GetPoorEvents();

	void SetBgaHeader(DA_BGAHeader value);
	void SetBgaEvents(DA_BGAEvent value);
	void SetLayerEvents(DA_BGAEvent value);
	void SetPoorEvents(DA_BGAEvent value);

private:
	DA_BGAHeader bga_header;
	DA_BGAEvent bga_events;
	DA_BGAEvent layer_events;
	DA_BGAEvent poor_events;
};