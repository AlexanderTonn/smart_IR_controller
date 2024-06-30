#include "ir.hpp"
#include <IRremote.hpp>
/**
 * @brief Method to initialize the IR receiver and sender
 *
 * @param recvPin
 * @param sendPin
 */
auto IR_Handle::init(const uint8_t recvPin,
                     const uint8_t sendPin) -> void
{
    IrReceiver.begin(recvPin);
    IrReceiver.start();
    IrSender.begin(sendPin);
}

/**
 * @brief Method to initialize the IR receiver and sender
 *
 * @param recvPin
 * @param ledFeedback
 */
auto IR_Handle::init(const uint8_t recvPin,
                     const uint8_t recvFeedbackLed,
                     const uint8_t sendPin) -> void
{

    IrReceiver.begin(recvPin, recvFeedbackLed);

    IrReceiver.start();
    IrSender.begin(sendPin);
}

/**
 * @brief
 *
 */
auto IR_Handle::run() -> int
{

    if (!IrReceiver.decode())
        return -1;

    auto ret = IrReceiver.decodedIRData.command;
    IrReceiver.resume();

    return ret;
}