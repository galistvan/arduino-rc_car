#include "RcCar.h"

void bluetoothCommand(char* command);

IndicatorHandler indicatorHandler(11, 12);
ServoReader leftRightServo(5, 1600, &indicatorHandler);
BluetoothHandler bluetoothHandler(10, 9, &bluetoothCommand);

//ServoReader forwardBackwardServo(6, 1500);

void setup() {
	Serial.begin(115200);
	indicatorHandler.setup();
	leftRightServo.setup();
	bluetoothHandler.setup();
}

void loop() {
	indicatorHandler.loop();
	leftRightServo.loop();
	bluetoothHandler.loop();
}

void bluetoothCommand(char* command) {
	if ((strcmp(command, "head") == 0)) {
		//headlight toggle
	} else if ((strcmp(command, "frta") == 0)) {
		//front-taillight toggle
	} else {
		Serial.println("unknown command");
	}
}
