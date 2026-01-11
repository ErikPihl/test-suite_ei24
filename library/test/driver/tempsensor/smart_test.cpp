/**
 * @brief Unit tests for the smart temperature sensor.
 */
#include <cstdint>

#include <gtest/gtest.h>

#include "arch/avr/hw_platform.h"
#include "driver/adc/stub.h"
#include "driver/tempsensor/smart.h"
#include "utils/utils.h"

#ifdef TESTSUITE

//! @todo Remove this #ifdef in lecture 1 to enable these tests.
#ifdef LECTURE1

namespace driver
{
namespace
{
// -----------------------------------------------------------------------------
constexpr double computeInputVoltage(const std::uint16_t adcVal) noexcept
{
    constexpr double supplyVoltage{5.0};
    constexpr std::uint16_t adcMax{1023U};

    // Convert the ADC value to a voltage.
    return static_cast<double>(adcVal) / adcMax * supplyVoltage;
}

// -----------------------------------------------------------------------------
constexpr std::int16_t convertToTemp(const double inputVoltage) noexcept
{
    // Convert voltage to temperature: T(°C) = 100 * V - 50.
    return utils::round<std::int16_t>(100.0 * inputVoltage - 50.0); 
}

// -----------------------------------------------------------------------------
constexpr std::int16_t convertToTemp(const std::uint16_t adcVal) noexcept
{
    // Convert ADC value to voltage, then to temperature.
    return convertToTemp(computeInputVoltage(adcVal));
}

/**
 * @brief Smart temp sensor initialization test.
 * 
 *        Verify that:
 *            - Invalid pin numbers are not accepted and the sensor is not initialized 
 *              for out-of-range values.
 *            - Untrained linear regression models aren't accepted.
 */
TEST(TempSensor_Smart, Initialization)
{
    //! @todo Add implementation here!
}

/**
 * @brief Smart temp sensor happy path test.
 * 
 *        Verify that the temp sensor predicts accurately when the model is properly trained 
 *        and valid input is provided.
 */
TEST(TempSensor_Smart, HappyPath)
{
    //! @todo Add implementation here!
}
} // namespace
} // namespace driver.

//! @todo Remove this #endif in lecture 1 to enable these tests.
#endif /** LECTURE1 */

#endif /** TESTSUITE */
