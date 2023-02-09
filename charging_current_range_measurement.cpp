#include "charging_current_range_measurement.hpp"

bool isLastCurrentMeasurement(const int& i, const int& f_size_of_current_charging_reading)
{
  if (i == (f_size_of_current_charging_reading - 1))
  {
    return true;
  }
  return false;
}

void updateCurrentChargingRange(std::vector<int>& f_current_charging_sequence,
                                std::map<std::string, int>& f_current_charging_readings_sequence)
{
  std::string charging_range =
      std::to_string(f_current_charging_sequence.front()) + "-" + std::to_string(f_current_charging_sequence.back());
  f_current_charging_readings_sequence[charging_range] = f_current_charging_sequence.size();
  f_current_charging_sequence.clear();
}

std::map<std::string, int> sequenceChargingCurrentReadings(std::vector<int> f_sorted_charging_current_readings)
{
  std::vector<int> current_charging_sequence;
  std::map<std::string, int> current_charging_readings_sequence;

  bool check_endof_sequence = false;

  for (int i = 0; i < static_cast<int>((f_sorted_charging_current_readings.size() - 1)); i++)
  {
    current_charging_sequence.push_back(f_sorted_charging_current_readings.at(i));
    if (!(abs((f_sorted_charging_current_readings.at(i + 1) - (f_sorted_charging_current_readings.at(i)))) <= 1))
    {
      updateCurrentChargingRange(current_charging_sequence, current_charging_readings_sequence);

      check_endof_sequence = isLastCurrentMeasurement(i, f_sorted_charging_current_readings.size());
    }
  }
  if (check_endof_sequence == false)
  {
    std::string charging_range = std::to_string(current_charging_sequence.front()) + "-" +
                                 std::to_string(f_sorted_charging_current_readings.back());
    current_charging_readings_sequence[charging_range] = current_charging_sequence.size() + 1;
  }
  return current_charging_readings_sequence;
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
