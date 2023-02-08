#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "charging_current_range_measurement.hpp"

std::vector<int> current_charging_range = {4, 5};
std::map<std::string, int> continous_range = {{4, 5, 2}};

TEST_CASE("Test Charging Current Measurement")
{
    REQUIRE(testChargingCurrentMeasurement(current_charging_range) == continous_range);
}
