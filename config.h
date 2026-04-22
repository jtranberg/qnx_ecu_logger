#ifndef CONFIG_H
#define CONFIG_H

struct Config {
    bool loggingEnabled;
    bool telemetryEnabled;
    int sendIntervalMs;
    int temperatureThreshold;
    int maxRetries;
    int retryDelayMs;
};

Config loadConfig(const char* filename);

#endif