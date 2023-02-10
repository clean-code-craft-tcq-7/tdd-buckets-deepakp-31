#include "charging_current_range_measurement.hpp"



int A2DConverter(int& f_rounded_of_current_reading_in_amps, int& f_reference_value, int& f_A2D_converter_bit)
{
  return ((std::pow(2, f_A2D_converter_bit) * f_rounded_of_current_reading_in_amps) / f_reference_value);
}

bool isValidA2DConvertedCurrentMeasurement(int& f_digital_current_reading, int& f_min_current, int& f_max_current)
{
  if ((f_min_current <= f_digital_current_reading) && (f_digital_current_reading <= f_max_current))
  {
    return true;
  }
  return false;
}



bool isLastCurrentMeasurement(const int& i, const int& f_size_of_current_charging_reading)
{
  if (i == (f_size_of_current_charging_reading - 1))
  {
    return true;
  }
  return false;
}

void updateCurrentChargingRangeAndReadings(std::vector<int>& f_current_charging_sequence,
                                           std::map<std::string, int>& f_current_charging_readings_sequence)
{
  std::string charging_range =
      std::to_string(f_current_charging_sequence.front()) + "-" + std::to_string(f_current_charging_sequence.back());
  f_current_charging_readings_sequence[charging_range] = f_current_charging_sequence.size();
  f_current_charging_sequence.clear();
}

std::map<std::string, int> sequenceOfMultipleChargingCurrentReadings(
    std::vector<int>& f_current_charging_sequence, std::map<std::string, int>& f_current_charging_readings_sequence,
    std::vector<int>& f_sorted_charging_current_readings)
{
  bool check_endof_sequence = false;

  for (int i = 0; i < static_cast<int>((f_sorted_charging_current_readings.size() - 1)); i++)
  {
    f_current_charging_sequence.push_back(f_sorted_charging_current_readings.at(i));
    if (!(abs((f_sorted_charging_current_readings.at(i + 1) - (f_sorted_charging_current_readings.at(i)))) <= 1))
    {
      updateCurrentChargingRangeAndReadings(f_current_charging_sequence, f_current_charging_readings_sequence);

      check_endof_sequence = isLastCurrentMeasurement(i, f_sorted_charging_current_readings.size());
    }
  }
  if (check_endof_sequence == false)
  {
    std::string charging_range = std::to_string(f_current_charging_sequence.front()) + "-" +
                                 std::to_string(f_sorted_charging_current_readings.back());
    f_current_charging_readings_sequence[charging_range] = f_current_charging_sequence.size() + 1;
  }
  return f_current_charging_readings_sequence;
}

std::map<std::string, int> sequenceChargingCurrentReadings(std::vector<int> f_sorted_charging_current_readings)
{
  std::vector<int> current_charging_sequence;
  std::map<std::string, int> current_charging_readings_sequence;

  if (f_sorted_charging_current_readings.size() == 1)
  {
    current_charging_sequence = f_sorted_charging_current_readings;

    updateCurrentChargingRangeAndReadings(current_charging_sequence, current_charging_readings_sequence);

    return current_charging_readings_sequence;
  }

  return sequenceOfMultipleChargingCurrentReadings(current_charging_sequence, current_charging_readings_sequence,
                                                   f_sorted_charging_current_readings);
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

  // Sorting
  sorted_charging_current_readings = sortChargingCurrentReadings(f_charging_current_readings);

  // Find Sequence
  auto sequence_charging_current_readings = sequenceChargingCurrentReadings(sorted_charging_current_readings);

  return sequence_charging_current_readings;
}
