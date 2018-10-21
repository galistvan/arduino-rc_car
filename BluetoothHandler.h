#pragma once

#include <Arduino.h>
#include <SoftwareSerial.h>

class BluetoothHandler {
public:
	BluetoothHandler(byte rxPin, byte txPin, void *bluetoothCommand(char* command));
	~BluetoothHandler();
	void setup();
	void loop();

private:
	const byte _rxPin;
	const byte _txPin;
	SoftwareSerial *bluetooth;
	void (*_bluetoothCommand)(char* command);
};
