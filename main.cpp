#include "logger.h"
#include "telemetry.h"

#include <chrono>
#include <thread>
#include <string>
#include <iostream>

int main() {
    std::cout << "Starting ECU logger simulation..." << std::endl;

    int temperature = 72;

    while (true) {
        std::string logMessage = "Engine temperature normal: " + std::to_string(temperature) + "C";
        std::string telemetryPayload = "temp=" + std::to_string(temperature);

        logEvent(logMessage);
        sendTelemetry(telemetryPayload);

        temperature++;

        if (temperature > 76) {
            temperature = 72;
        }

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}