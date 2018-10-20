#pragma once
//This is the header of the RC car indicator, it can be the left or the right indicator as well.
#include <Arduino.h>

//#include "Runnable.h"

class Indicator {
public:
	Indicator(byte indicatorPin, int blinkTime);
//	~Indicator();
	void setup();
	void loop();
	void on();
	void off();
	bool status();

private:
	const byte _indicatorPin;
	const int _blinkTime;
	bool _isOn;
	bool _blinkStatus;
	unsigned long _sinceLastChangeInMillis;
};
