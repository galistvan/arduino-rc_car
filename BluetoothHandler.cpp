#include "BluetoothHandler.h"

char *array;

BluetoothHandler::BluetoothHandler(byte rxPin, byte txPin, void *bluetoothCommand(char* command)) :
		_rxPin(rxPin), _txPin(txPin), _bluetoothCommand(bluetoothCommand) {
}

BluetoothHandler::~BluetoothHandler() {
	delete bluetooth;
	delete[] array;
}

void BluetoothHandler::setup() {
	bluetooth = new SoftwareSerial(_rxPin, _txPin);
	bluetooth->begin(9600);
	array = new char[5];
}

void BluetoothHandler::loop() {
	if (bluetooth->available() == 4) {
		bluetooth->readBytes(array, 4);
		array[4]='\0';
		_bluetoothCommand(array);
//		delete[] array;
//		array = new char[5];
	}
}
