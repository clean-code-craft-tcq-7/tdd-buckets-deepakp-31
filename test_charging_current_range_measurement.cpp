#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "charging_current_range_measurement.hpp"

TEST_CASE("Test case for 12-bit A2D converter")
{
  std::vector<int> rounded_current_reading_in_amps = {10, 0, 3};
  std::vector<int> digital_current_reading = {4094, 0, 1146};

  for (int iterator = 0; iterator < digital_current_reading.size(); iterator++)
  {
    REQUIRE(A2DConverter(rounded_current_reading_in_amps.at(iterator)) == digital_current_reading.at(iterator));
  }
}

TEST_CASE("Test case Validity of A2D converted Current Measurement")
{
  std::vector<int> digital_current_reading = {4095, 4094, 0, -1};
  std::vector<bool> validty_of_digital_current_reading = {false, true, true, false};

  for (int iterator = 0; iterator < digital_current_reading.size(); iterator++)
  {
    REQUIRE(isValidA2DConvertedCurrentMeasurement(digital_current_reading.at(iterator)) == validty_of_digital_current_reading.at(iterator));
  }
}

TEST_CASE("Test case for sequenceChargingCurrentReadings")
{
  // 2 measurements
  std::vector<int> sorted_charging_current_readings = {4, 5};
  std::map<std::string, int> sequence_charging_current_readings = {{"4-5", 2}};
  REQUIRE(sequenceChargingCurrentReadings(sorted_charging_current_readings) == sequence_charging_current_readings);

  // 1 measurements
  sorted_charging_current_readings = {1};
  sequence_charging_current_readings = {{"1-1", 1}};
  REQUIRE(sequenceChargingCurrentReadings(sorted_charging_current_readings) == sequence_charging_current_readings);

  // 3 measurements
  sorted_charging_current_readings = {4, 5, 6};
  sequence_charging_current_readings = {{"4-6", 3}};
  REQUIRE(sequenceChargingCurrentReadings(sorted_charging_current_readings) == sequence_charging_current_readings);

  sorted_charging_current_readings = {4, 4, 5};
  sequence_charging_current_readings = {{"4-5", 3}};
  REQUIRE(sequenceChargingCurrentReadings(sorted_charging_current_readings) == sequence_charging_current_readings);

  sorted_charging_current_readings = {4, 4, 4};
  sequence_charging_current_readings = {{"4-4", 3}};
  REQUIRE(sequenceChargingCurrentReadings(sorted_charging_current_readings) == sequence_charging_current_readings);

  // unsorted multiple measurements with some single measurements
  auto unsorted_charging_current_readings = {7, 2, 10, 9};
  sequence_charging_current_readings = {{"2-2", 1}, {"7-7", 1}, {"9-10", 2}};
  REQUIRE(sequenceChargingCurrentReadings(sortChargingCurrentReadings(unsorted_charging_current_readings)) ==
          sequence_charging_current_readings);
}
TEST_CASE("Test case for  sortChargingCurrentReadings")
{
  std::vector<int> charging_current_readings = {100, 3, 7, 8, 23, 56, 3, 3, 8, 56, 2, 8, 3};
  std::vector<int> sorted_charging_current_readings = {2, 3, 3, 3, 3, 7, 8, 8, 8, 23, 56, 56, 100};
  REQUIRE(sortChargingCurrentReadings(charging_current_readings) == sorted_charging_current_readings);
}
TEST_CASE("Test testChargingCurrentMeasurement")
{
  // 2 measurements
  std::vector<int> current_charging_range = {4, 5};
  std::map<std::string, int> continous_range = {{"4-5", 2}};
  REQUIRE(testChargingCurrentMeasurement(current_charging_range) == continous_range);

  // 1 measurements
  current_charging_range = {8};
  continous_range = {{"8-8", 1}};
  REQUIRE(testChargingCurrentMeasurement(current_charging_range) == continous_range);

  // 3 measurements
  current_charging_range = {2, 3, 4};
  continous_range = {{"2-4", 3}};
  REQUIRE(testChargingCurrentMeasurement(current_charging_range) == continous_range);

  // multiple measurements
  current_charging_range = {3, 3, 5, 4, 10, 11, 12, 9, 7, 6, 5, 10, 23, 23, 22, 20};
  continous_range = {{"3-7", 7}, {"9-12", 5}, {"20-20", 1}, {"22-23", 3}};
  REQUIRE(testChargingCurrentMeasurement(current_charging_range) == continous_range);
  // unsorted multiple measurements with some single measurements

  current_charging_range = {5, 3, 11, 4, 10, 3, 12};
  continous_range = {{"3-5", 4}, {"10-12", 3}};
  REQUIRE(testChargingCurrentMeasurement(current_charging_range) == continous_range);
}
