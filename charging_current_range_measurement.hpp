#pragma once

#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> sequenceChargingCurrentReadings(std::vector<int> f_sorted_charging_current_readings);

std::vector<int> sortChargingCurrentReadings(std::vector<int> f_charging_current_readings);

std::map<std::string, int> testChargingCurrentMeasurement(std::vector<int> chargingCurrentReadings);
