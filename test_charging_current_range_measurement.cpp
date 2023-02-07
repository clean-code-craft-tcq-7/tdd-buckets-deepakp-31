#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "charging_current_range_measurement.hpp"

TEST_CASE("Test Charging Current Measurement")
{
    REQUIRE(testChargingCurrentMeasurement({4, 5}) == "4-5, 2");
}