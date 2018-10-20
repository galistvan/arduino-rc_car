#include "RcCar.h"

IndicatorHandler indicatorHandler(11,12);
ServoReader leftRightServo(5, 1600, &indicatorHandler);
//ServoReader forwardBackwardServo(6, 1500);

void setup() {
	Serial.begin(115200);
	indicatorHandler.setup();
	leftRightServo.setup();

}

void loop() {
	indicatorHandler.loop();
	leftRightServo.loop();

	indicatorHandler.warningSign();
}

