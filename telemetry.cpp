#include "telemetry.h"
#include <chrono>
#include <iostream>
#include <random>
#include <thread>

bool trySendOnce(const std::string& data) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(1, 100);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    int roll = dist(gen);

    if (roll <= 30) {
        std::cout << "Sending telemetry: " << data << std::endl;
        return true;
    }

    std::cout << "Telemetry send failed: " << data << std::endl;
    return false;
}

bool sendTelemetryWithRetry(
    const std::string& data,
    int maxRetries,
    int retryDelayMs
) {
    for (int attempt = 1; attempt <= maxRetries; ++attempt) {
        std::cout << "Attempt " << attempt << "/" << maxRetries << ": ";
        bool success = trySendOnce(data);

        if (success) {
            return true;
        }

        if (attempt < maxRetries) {
            std::cout << "Retrying in " << retryDelayMs << " ms..." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(retryDelayMs));
        }
    }

    return false;
}