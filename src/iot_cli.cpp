#include "iot_cli.hpp"

/**
 * @brief Send Message to Arduino IOT 
 * 
 * @param message 
 */
auto IOT_CLI::sendLogMessage(String message) -> void {
    Serial.println(message);
}