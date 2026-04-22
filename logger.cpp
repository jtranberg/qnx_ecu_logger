#include "logger.h"
#include <fstream>
#include <iostream>

void logEvent(const std::string& message) {
    std::ofstream logFile("ecu_log.txt", std::ios::app);

    if (!logFile.is_open()) {
        std::cerr << "Failed to open ecu_log.txt for writing." << std::endl;
        return;
    }

    logFile << "[LOG] " << message << std::endl;
}