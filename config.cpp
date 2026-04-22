#include "config.h"
#include <fstream>
#include <iostream>
#include <string>

Config loadConfig(const char* filename) {
    Config config{};
    config.loggingEnabled = true;
    config.telemetryEnabled = true;
    config.sendIntervalMs = 2000;
    config.temperatureThreshold = 75;

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open config file. Using defaults." << std::endl;
        return config;
    }

    std::string key;
    std::string value;

    while (file >> key >> value) {
        if (key == "logging_enabled") {
            config.loggingEnabled = (value == "true");
        } else if (key == "telemetry_enabled") {
            config.telemetryEnabled = (value == "true");
        } else if (key == "send_interval_ms") {
            config.sendIntervalMs = std::stoi(value);
        } else if (key == "temperature_threshold") {
            config.temperatureThreshold = std::stoi(value);
        }
    }

    return config;
}