#pragma once
#include "Bmson.h"

constexpr int FINDMES_X = 640;
constexpr int FINDMES_VER = 32;
constexpr int FINDMES_INF = 48;
constexpr int FINDMES_LIN = 64;
constexpr int FINDMES_BPS = 80;
constexpr int FINDMES_STS = 96;
constexpr int FINDMES_SCS = 112;
constexpr int FINDMES_BGA = 128;

void OpenBmson(String filePath);
void CloseBmson();

Bmson GetBmson();