#include <Arduino.h>

#include "ServoReader.h"

int value = 0;

ServoReader::ServoReader(
		byte servoPin,
		int centerValue,
		IndicatorHandler *pIndicatorHandler) : //very tight coupled
		_servoPin(servoPin),
		_centerValue(centerValue)
		 {
	_pIndicatorHandler = pIndicatorHandler;
}

void ServoReader::setup() {
	pinMode(_servoPin, INPUT);
}

void ServoReader::loop() {
	value = pulseIn(_servoPin, HIGH);
	if (value != 0) {
		if (value >= _centerValue + 50 ){
			_pIndicatorHandler->turnRight();
		} else if (value <= _centerValue - 50){
			_pIndicatorHandler->turnLeft();
		} else {
			_pIndicatorHandler->noTurn();
		}
	}
}

