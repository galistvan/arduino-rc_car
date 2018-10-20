#include "IndicatorHandler.h"

IndicatorHandler::IndicatorHandler(byte leftPin, byte rightPin) :
		_leftIndicator(leftPin, INDICATOR_BLINK_TIME_MS),
		_rightIndicator(rightPin, INDICATOR_BLINK_TIME_MS),
		_isWarningSign(false) {
}

//IndicatorHandler::~IndicatorHandler() {
//
//}

void IndicatorHandler::setup() {
	_leftIndicator.setup();
	_rightIndicator.setup();
}

void IndicatorHandler::loop() {
	_leftIndicator.loop();
	_rightIndicator.loop();
}

void IndicatorHandler::turnLeft() {
	if (!_isWarningSign){
		_leftIndicator.on();
		_rightIndicator.off();
	}
}

void IndicatorHandler::turnRight() {
	if (!_isWarningSign){
		_leftIndicator.off();
		_rightIndicator.on();
	}
}

void IndicatorHandler::noTurn(){
	if (!_isWarningSign){
		this->turnOffEverySign();
	}
}

void IndicatorHandler::turnOffEverySign() {
	_isWarningSign = false;
	_leftIndicator.off();
	_rightIndicator.off();
}

void IndicatorHandler::warningSign() {
	_isWarningSign = true;
	if (_leftIndicator.status() != _rightIndicator.status()) {
		_leftIndicator.off();
		_rightIndicator.off();
	}
	_leftIndicator.on();
	_rightIndicator.on();
}
