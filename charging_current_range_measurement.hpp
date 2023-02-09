#pragma once

#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <algorithm>

bool isLastCurrentMeasurement(const int& i, const int& f_size_of_current_charging_reading);

std::map<std::string, int> insertCurrentChargingRange(std::vector<int>& f_current_charging_sequence,
                                                      std::map<std::string, int>& f_current_charging_readings_sequence);

std::map<std::string, int> sequenceChargingCurrentReadings(std::vector<int> f_sorted_charging_current_readings);

std::vector<int> sortChargingCurrentReadings(std::vector<int> f_charging_current_readings);

std::map<std::string, int> testChargingCurrentMeasurement(std::vector<int> chargingCurrentReadings);
