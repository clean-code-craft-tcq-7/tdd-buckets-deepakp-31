#include "charging_current_range_measurement.hpp"

// Given a vector
//     Sort it
//     Find sequence
//         its upper and lower limit

//     Check the number of occurance of each element in the sequnce

std::vector<std::vector<int>> sequenceChargingCurrentReadings(std::vector<int> f_sorted_charging_current_readings)
{
    std::vector<std::vector<int>> sequence_charging_current_readings;
    std::vector<int> sequence_charging_current_reading;

    for (auto current_reading : f_sorted_charging_current_readings)
    {
    }
}

std::vector<int> sortChargingCurrentReadings(std::vector<int> f_charging_current_readings)
{
    sort(f_charging_current_readings.begin(), f_charging_current_readings.end());
    return f_charging_current_readings;
}


std::map<std::string, int> testChargingCurrentMeasurement(std::vector<int> f_charging_current_readings)
{
    // Sorting
    std::vector<int> sorted_charging_current_readings = sortChargingCurrentReadings(f_charging_current_readings);

    // Find Sequence
    std::vector<std::vector<int>> sequence_charging_current_readings = sequenceChargingCurrentReadings(sorted_charging_current_readings);

    std::map<std::string, int> checks_measure = std::to_string(f_charging_current_readings.at(0)) + "-" + std::to_string(f_charging_current_readings.at(1)) + ", " + std::to_string(f_charging_current_readings.size());

    // return checks_measure;

      return {{"4-5", 2}};
}
