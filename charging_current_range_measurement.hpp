#pragma once

#ifndef CHARGING_CURRENT_RANGE_MEASUREMENT
#define CHARGING_CURRENT_RANGE_MEASUREMENT

#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

// A2D Converted
int A2DConverter(int& f_rounded_current_reading_in_amps, int& f_reference_value, int& f_A2D_converter_bit);

//Checking validity of an A2D converted current measurement
bool isValidA2DConvertedCurrentMeasurement(int& f_digital_current_reading, int& f_min_current, int& f_max_current);

// Function if last element in the vector
bool isLastCurrentMeasurement(const int& i, const int& f_size_of_current_charging_reading);

// Function to update each charging Range & Readings
void updateCurrentChargingRangeAndReadings(std::vector<int>& f_current_charging_sequence,
                                           std::map<std::string, int>& f_current_charging_readings_sequence);

// Function to create the map with sequence of multiple current readings
std::map<std::string, int> sequenceOfMultipleChargingCurrentReadings(
    std::vector<int>& f_current_charging_sequence, std::map<std::string, int>& f_current_charging_readings_sequence,
    std::vector<int>& f_sorted_charging_current_readings);

// Function to create the map with sequence of current readings
std::map<std::string, int> sequenceChargingCurrentReadings(std::vector<int> f_sorted_charging_current_readings);

// Function to return sorted charging current readings
std::vector<int> sortChargingCurrentReadings(std::vector<int> f_charging_current_readings);

// Function to test Charging Current Measurement
std::map<std::string, int> testChargingCurrentMeasurement(std::vector<int> chargingCurrentReadings);

#endif
