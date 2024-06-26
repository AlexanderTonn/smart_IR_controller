#include "ir_receiver.hpp"

#include <IRremote.hpp>

// IR_Handle::IR_Handle(IRrecv &_IRrecv) : mObject(_IRrecv) {}

/**
 * @brief 
 * 
 * @param recvPin 
 * @param ledFeedback 
 */
auto IR_Handle::init(const uint16_t recvPin , const bool ledFeedbackActive) -> void {
    IrReceiver.begin(recvPin, ledFeedbackActive);
}

/**
 * @brief 
 * 
 */
auto IR_Handle::run() -> int {

    if(!IrReceiver.decode())
        return -1; 

    auto ret = IrReceiver.decodedIRData.command;
   IrReceiver.resume();

    return ret;
}