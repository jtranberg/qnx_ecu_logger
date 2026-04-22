#include "telemetry.h"
#include <chrono>
#include <iostream>
#include <thread>

void sendTelemetry(const std::string& data) {
    std::thread([data]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Sending telemetry: " << data << std::endl;
    }).detach();
}