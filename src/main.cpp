#include "ir.hpp"
#include "io.hpp"
#include "iot_cli.hpp"
#include "pinMapping.hpp"
#include "thingproperties.h"

#include <Arduino.h>

IR_Handle _irHandle;
IO _io;

void setup() {

  Serial.begin(9600);

  _io.reservePin(IR_RECEIVER, IO::pinMode::DIGITAL_IN);
  _io.reservePin(IR_TRANSMITTER, IO::pinMode::DIGITAL_OUT);
  
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  _irHandle.init(IR_RECEIVER, IR_TRANSMITTER);

}

void loop() {
  //ArduinoCloud.update();

  auto ret = _irHandle.run();

  Serial.println(ret);
  delay(1000);

}
