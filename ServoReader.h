#pragma once

//#include "Runnable.h"

#include "IndicatorHandler.h"

class ServoReader {
public:
		ServoReader(
				byte servoPin,
				int centerValue,
				IndicatorHandler *pIndicatorHandler);
//	ServoReader(
//			byte servoPin,
//			int centerValue,
//			void *moreThanCenter,
//			void *lessThanCenter,
//			void *aroundCenter);
//	~ServoReader();
	void setup();
	void loop();

private:
	const byte _servoPin;
	const int _centerValue;

	IndicatorHandler *_pIndicatorHandler;
//	void (*_moreThanCenter)(void);
//	void (*_lessThanCenter)(void);
//	void (*_aroundCenter)(void);
};
