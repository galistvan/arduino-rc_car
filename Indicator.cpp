#include <Arduino.h>

#include "Indicator.h"

Indicator::Indicator(byte indicatorPin, int blinkTime) :
		_indicatorPin(indicatorPin), _blinkTime(blinkTime) {
	_isOn = false;
	_blinkStatus = false;
	_sinceLastChangeInMillis = 0;
}

void Indicator::setup() {
	pinMode(_indicatorPin, OUTPUT);
}

void Indicator::loop() {
	if (_isOn) {
		if (millis() - _sinceLastChangeInMillis > _blinkTime) {
			digitalWrite(_indicatorPin, !digitalRead(_indicatorPin));
			_sinceLastChangeInMillis = millis();
		}
	}
}

void Indicator::on() {
	if (!_isOn) {
		_isOn = true;
		_sinceLastChangeInMillis = millis();
		digitalWrite(_indicatorPin, HIGH);
	}
}

void Indicator::off() {
	if (_isOn) {
		_isOn = false;
		digitalWrite(_indicatorPin, LOW);
	}
}

bool Indicator::status() {
	return _isOn;
}
