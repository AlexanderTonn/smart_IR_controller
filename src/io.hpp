/**
 * @file io.hpp
 * @author Alexander Tonn
 * @brief IO Class for handling the input and outputs
 * @version 0.1
 * @date 2024-06-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef IO_HPP
#define IO_HPP

#include <Array.h>
#include <assert.h>

class IO
{
private:
    #if defined (ARDUINO_SAMD_MKRWIFI1010)
        constexpr static uint8_t MAX_PIN_COUNT = 21;
    #endif

    // Array 1 - stores boolean state whether it's assumed or not
    // Array 2 - stores the raw data
    Array<Array<int8_t, MAX_PIN_COUNT>, 2> mDigitalPins;


    public:
    enum class pinMode
    {
        DIGITAL_IN = 0,
        DIGITAL_OUT = 1,
        ANALOG_IN = 2,
        ANALOG_OUT = 3
    };

    auto reservePin(const uint8_t, pinMode) -> bool;
    auto getValue(const uint8_t) -> int32_t;
    auto setValue(const uint8_t, const int32_t) -> void;
};

    


#endif