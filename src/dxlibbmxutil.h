#pragma once
#include "./bmson/dxlibbmson.h"

constexpr int ID_BMXUTIL_ERROR		= -1;
constexpr int ID_BMXUTIL_ZERO		= 0;
constexpr int ID_BMXUTIL_BMS5		= 1;
constexpr int ID_BMXUTIL_BMS7		= 2;
constexpr int ID_BMXUTIL_BMS14		= 3;
constexpr int ID_BMXUTIL_BMS9		= 4;
constexpr int ID_BMXUTIL_BMSON5		= 5;
constexpr int ID_BMXUTIL_BMSON7		= 6;
constexpr int ID_BMXUTIL_BMSON14	= 7;
constexpr int ID_BMXUTIL_BMSON9		= 8;

constexpr int ID_BMXUTIL_BMS = ID_BMXUTIL_BMS7;
constexpr int ID_BMXUTIL_BME = ID_BMXUTIL_BMS7;
constexpr int ID_BMXUTIL_BML = ID_BMXUTIL_BMS7;
constexpr int ID_BMXUTIL_PMS = ID_BMXUTIL_BMS9;
constexpr int ID_BMXUTIL_BMSON = ID_BMXUTIL_BMSON7;
constexpr int ID_BMXUTIL_PMSON = ID_BMXUTIL_BMSON9;

int WhatsThisBmx(const String filePath);
