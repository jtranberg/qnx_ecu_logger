#include "logger.h"
#include "telemetry.h"
#include "config.h"

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

int main() {
    Config config = loadConfig("config.txt");

    std::cout << "Starting ECU logger simulation..." << std::endl;
    std::cout << "Logging enabled: " << (config.loggingEnabled ? "true" : "false") << std::endl;
    std::cout << "Telemetry enabled: " << (config.telemetryEnabled ? "true" : "false") << std::endl;
    std::cout << "Send interval (ms): " << config.sendIntervalMs << std::endl;
    std::cout << "Temperature threshold: " << config.temperatureThreshold << "C" << std::endl;

    int temperature = 72;

    while (true) {
        std::string state = (temperature >= config.temperatureThreshold) ? "HIGH" : "NORMAL";
        std::string logMessage = "Engine temperature " + state + ": " + std::to_string(temperature) + "C";
        std::string telemetryPayload =
            "temp=" + std::to_string(temperature) + ",state=" + state;

        if (config.loggingEnabled) {
            logEvent(logMessage);
        }

        if (config.telemetryEnabled) {
            sendTelemetry(telemetryPayload);
        }

        temperature++;

        if (temperature > 76) {
            temperature = 72;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(config.sendIntervalMs));
    }

    return 0;
}