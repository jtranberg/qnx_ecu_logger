#ifndef TELEMETRY_H
#define TELEMETRY_H

#include <string>

bool sendTelemetryWithRetry(
    const std::string& data,
    int maxRetries,
    int retryDelayMs
);

#endif