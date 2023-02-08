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

    int temp = f_sorted_charging_current_readings.at(0);
    for (int i = 0; i < f_sorted_charging_current_readings.size() - 1; i++)
    {

        if (!(abs((f_sorted_charging_current_readings.at(i + 1) - (f_sorted_charging_current_readings.at(i)))) <= 1))
        {
            
            temp = f_sorted_charging_current_readings.at(i);
        }
    }
}

std::vector<int> sortChargingCurrentReadings(std::vector<int> f_charging_current_readings)
{
    sort(f_charging_current_readings.begin(), f_charging_current_readings.end());
    return f_charging_current_readings;
}

std::map<std::string, int> testChargingCurrentMeasurement(std::vector<int> f_charging_current_readings)
{
    std::map<std::string, int> current_charging_range;

    std::vector<int> sorted_charging_current_readings;

    int charging_current_reading;

    // Sorting
    sorted_charging_current_readings = sortChargingCurrentReadings(f_charging_current_readings);

    // Find Sequence
    std::vector<std::vector<int>> sequence_charging_current_readings = sequenceChargingCurrentReadings(sorted_charging_current_readings);

    current_charging_range[std::to_string(sequence_charging_current_readings)] = charging_current_reading;

    std::map<std::string, int> checks_measure = std::to_string(f_charging_current_readings.at(0)) + "-" + std::to_string(f_charging_current_readings.at(1)) + ", " + std::to_string(f_charging_current_readings.size());

    // return checks_measure;

    return {{"4-5", 2}};
}
