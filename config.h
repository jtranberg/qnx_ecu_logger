#ifndef CONFIG_H
#define CONFIG_H

struct Config {
    bool loggingEnabled;
    bool telemetryEnabled;
    int sendIntervalMs;
    int temperatureThreshold;
};

Config loadConfig(const char* filename);

#endif