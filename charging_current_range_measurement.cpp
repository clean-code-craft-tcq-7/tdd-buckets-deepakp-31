#include "charging_current_range_measurement.hpp"

// Given a vector
//     Sort it
//     Find sequence
//         its upper and lower limit

//     Check the number of occurance of each element in the sequnce

std::map<std::string, int> sequenceChargingCurrentReadings(std::vector<int> f_sorted_charging_current_readings)
{
    // std::vector<std::vector<int>> sequence_charging_current_readings;
    std::vector<int> sequence_charging_current_reading;
    std::map<std::string, int> sequence_charging_current_readings;

    bool check_endof_sequence = false;

    int temp = f_sorted_charging_current_readings.at(0);
    for (int i = 0; i < (f_sorted_charging_current_readings.size() - 1); i++)
    {

        sequence_charging_current_reading.push_back(f_sorted_charging_current_readings.at(i));
        if (!(abs((f_sorted_charging_current_readings.at(i + 1) - (f_sorted_charging_current_readings.at(i)))) <= 1))
        {

            std::string charging_range = std::to_string(sequence_charging_current_reading.front()) 
                                            + "-" + std::to_string(sequence_charging_current_reading.back());
            sequence_charging_current_readings[charging_range] = sequence_charging_current_reading.size();
            sequence_charging_current_reading.clear();

            if (i == (f_sorted_charging_current_readings.size() - 1))
            {
                check_endof_sequence = true;
            }
        }
    }
    if (check_endof_sequence == false)
    {

        std::string charging_range = std::to_string(sequence_charging_current_reading.front()) 
                                        + "-" + std::to_string(f_sorted_charging_current_readings.back());
        sequence_charging_current_readings[charging_range] = sequence_charging_current_reading.size() + 1;
    }
    return sequence_charging_current_readings;
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
    auto sequence_charging_current_readings = sequenceChargingCurrentReadings(sorted_charging_current_readings);

    return sequence_charging_current_readings;
}
