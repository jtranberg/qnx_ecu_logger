#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

void logEvent(const std::string& message) {
    std::ofstream logFile("ecu_log.txt", std::ios::app);

    if (logFile.is_open()) {
        logFile << "[LOG] " << message << std::endl;
        logFile.close();
    }
}

// Simulated telemetry send (non-blocking idea)
void sendTelemetry(const std::string& data) {
    std::thread([data]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate delay
        std::cout << "Sending telemetry: " << data << std::endl;
    }).detach();
}

int main() {
    while (true) {
        logEvent("Engine temperature normal");

        sendTelemetry("temp=72");

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}