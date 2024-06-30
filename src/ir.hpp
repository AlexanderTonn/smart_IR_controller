// IR Receiver handler
#ifndef IR_HANDLE_H
#define IR_HANDLE_H

#include <Arduino.h>

class IR_Handle
{

private:
    uint8_t mReceiverPin = 0; // Pin to receive IR signal

public:
    auto init(const uint8_t,
              const uint8_t,
              const uint8_t) -> void;   
    auto init(const uint8_t , const uint8_t ) -> void;

    auto run() -> int;
};

#endif