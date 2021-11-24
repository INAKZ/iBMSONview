#pragma once

#include "Bmson.h"
#include "../util/util.h"
#include "rapidjson/document.h"
#include <fstream>

int OpenBmson(String filePath);
void CloseBmson();

Bmson* GetBmson();

static void ResetTmp();
static void ResetTmps();
static void ResetTmpbl();
static void ResetTmpsc();
static void ResetTmpn();
static void ResetTmpns();
static void ResetTmpbe();
static void ResetTmpse();
static void ResetTmpbgah();
static void ResetTmpbgae();
static void ResetTmpbgahs();
static void ResetTmpbgaes();
