#include "charging_current_range_measurement.hpp"

std::string testChargingCurrentMeasurement(std::vector<int> chargingCurrentReadings)
{
    std::string checks_measure = std::to_string(chargingCurrentReadings.at(0)) + "-" + std::to_string(chargingCurrentReadings.at(1)) + ", " + std::to_string(chargingCurrentReadings.size());

    return checks_measure;
}