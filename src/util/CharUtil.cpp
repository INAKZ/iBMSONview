#include "CharUtil.h"

boolean IsNaturalNumber(char c) {
	if (c == '0' ||
		c == '1' ||
		c == '2' ||
		c == '3' ||
		c == '4' ||
		c == '5' ||
		c == '6' ||
		c == '7' ||
		c == '8' ||
		c == '9') {
		return true;
	} else {
		return false;
	}
}
boolean IsIntegerNumber(char c) {
	if (c == '0' ||
		c == '1' ||
		c == '2' ||
		c == '3' ||
		c == '4' ||
		c == '5' ||
		c == '6' ||
		c == '7' ||
		c == '8' ||
		c == '9' ||
		c == '-' ||
		c == '+') {
		return true;
	}
	else {
		return false;
	}
}
boolean IsDecimalNumber(char c) {
	if (c == '0' ||
		c == '1' ||
		c == '2' ||
		c == '3' ||
		c == '4' ||
		c == '5' ||
		c == '6' ||
		c == '7' ||
		c == '8' ||
		c == '9' ||
		c == '-' ||
		c == '+' ||
		c == '.') {
		return true;
	}
	else {
		return false;
	}
}