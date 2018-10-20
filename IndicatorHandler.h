#pragma once

//#include "Runnable.h"

#include "Indicator.h"

//This should encapsulate the two indicator, and handle the warning sign (when both direction is blinking)
#define INDICATOR_BLINK_TIME_MS 450

class IndicatorHandler {
public:
	IndicatorHandler(byte leftPin, byte rightPin);
//	~IndicatorHandler();
	void setup();
	void loop();
	void turnLeft();
	void turnRight();
	void noTurn();
	void turnOffEverySign();
	void warningSign();
private:
	const Indicator _leftIndicator;
	const Indicator _rightIndicator;
	bool _isWarningSign;
};


