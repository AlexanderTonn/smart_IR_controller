#include "ir_receiver.hpp"
#include "iot_cli.hpp"
#include "thingproperties.h"

#include <Arduino.h>

IR_Handle _irHandle;

void setup() {

  Serial.begin(9600);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  // ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  _irHandle.init(0, true);

}

void loop() {
  ArduinoCloud.update();

  auto ret = _irHandle.run();

  Serial.println(ret);
  delay(1000);

}
