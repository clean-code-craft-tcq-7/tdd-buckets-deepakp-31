#pragma once

#ifndef CHARGING_CURRENT_RANGE_MEASUREMENT
#define CHARGING_CURRENT_RANGE_MEASUREMENT

#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

int reference_current = 10;
int A2D_12_bit_converter_bit = 12;
int min_12_bit_digital_current = 0;
int max_12_bit_digital_current = 4094;

int max_reference_current = 15;
int min_reference_current = -15;
int A2D_10_bit_converter_bit = 10;
int min_10_bit_digital_current = 0;
int max_10_bit_digital_current = 1022;

int A2D10BitConverter(int f_rounded_current_reading_in_amps);

int A2DConverter(int f_rounded_current_reading_in_amps);

bool isValidA2DConvertedCurrentMeasurement(int &f_digital_current_reading, int &f_min_current, int &f_max_current);

// Function if last element in the vector
bool isLastCurrentMeasurement(const int &i, const int &f_size_of_current_charging_reading);

// Function to update each charging Range & Readings
void updateCurrentChargingRangeAndReadings(std::vector<int> &f_current_charging_sequence,
                                           std::map<std::string, int> &f_current_charging_readings_sequence);

// Function to create the map with sequence of multiple current readings
std::map<std::string, int> sequenceOfMultipleChargingCurrentReadings(
    std::vector<int> &f_current_charging_sequence, std::map<std::string, int> &f_current_charging_readings_sequence,
    std::vector<int> &f_sorted_charging_current_readings);

// Function to create the map with sequence of current readings
std::map<std::string, int> sequenceChargingCurrentReadings(std::vector<int> f_sorted_charging_current_readings);

// Function to return sorted charging current readings
std::vector<int> sortChargingCurrentReadings(std::vector<int> f_charging_current_readings);

// Function to test Charging Current Measurement
std::map<std::string, int> testChargingCurrentMeasurement(std::vector<int> chargingCurrentReadings);

#endif
