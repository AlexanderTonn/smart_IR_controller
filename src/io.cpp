#include "io.hpp"
/**
 * @brief
 *
 * @param pin
 * @param _pinMode
 * @return true
 * @return false
 */
auto IO::reservePin(const uint8_t pin, pinMode _pinMode) -> bool
{
    // Already reserved
    if (mDigitalPins.at(pin).at(0) == true)
    {
        Serial.println("Digital Pin :" + String(pin) + " already reserved");
        return false;
    }

    mDigitalPins.at(pin).at(0) = true;
    mDigitalPins.at(pin).at(1) = static_cast<int>(_pinMode);

    return true;
}
/**
 * @brief Read the value from the pin
 *
 * @param pin Pin no. to read from
 * @return int32_t
 */
auto IO::getValue(const uint8_t pin) -> int32_t
{
    if (mDigitalPins.at(pin).at(0) == false)
    {
        Serial.println("Pin " + String(pin) + " is not reserved");
        return -1;
    }

    const auto pinMode = static_cast<int32_t>(mDigitalPins.at(pin).at(1));
    int32_t ret = 0;
    switch (pinMode)
    {
    case static_cast<int>(pinMode::DIGITAL_IN):
        ret = digitalRead(pin);
        break;
    case static_cast<int>(pinMode::DIGITAL_OUT):
        Serial.println("Pin " + String(pin) + "Cannot read from a digital output pin.");
        break;
    case static_cast<int>(pinMode::ANALOG_IN):
        ret = analogRead(pin);
        break;
    case static_cast<int>(pinMode::ANALOG_OUT):
        Serial.println("Pin " + String(pin) + "Cannot read from a analog output pin.");
        break;
    default:
        return -1;
        break;
    }

    return ret;
}
/**
 * @brief Set the value of the pin
 * 
 * @param pin target pin
 * @param setValue value to set
 */
auto IO::setValue(const uint8_t pin, const int32_t setValue) -> void
{
    if (mDigitalPins.at(pin).at(0) == false)
    {
        Serial.println("Pin " + String(pin) + " is not reserved");
        return;
    }

    const auto pinMode = static_cast<int32_t>(mDigitalPins.at(pin).at(1));

    switch (pinMode)
    {
    case static_cast<int>(pinMode::DIGITAL_IN):
        Serial.println("Pin " + String(pin) + "cannot write to a digital input pin.");
        break;
    case static_cast<int>(pinMode::DIGITAL_OUT):

        if (setValue < 0 || setValue > 1)
        {
            Serial.println("Pin " + String(pin) + "defined as Digital Output - value is out of range.");
            return;
        }

        digitalWrite(pin, setValue);

        break;
    case static_cast<int>(pinMode::ANALOG_IN):
        Serial.println("Pin " + String(pin) + "cannot write to a analog input pin.");
        break;
    case static_cast<int>(pinMode::ANALOG_OUT):

        analogWrite(pin, setValue);
        
        break;
    default:
        return;
        break;
    }
}