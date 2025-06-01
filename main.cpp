#include "weather_data.hpp"
#include "current_condition_display.hpp"
#include "statistics_display.hpp"
#include "forecast_display.hpp"
#include <memory>

int main()
{
    auto currentConditionDisplay = std::make_shared<ws::CurrentConditionDisplay>();
    auto statisticDisplay = std::make_shared<ws::StatisticsDisplay>();
    auto forecastDisplay = std::make_shared<ws::ForecastDisplay>();

    ws::WeatherData weatherData;

    weatherData.registerObserver(currentConditionDisplay);
    weatherData.registerObserver(statisticDisplay);
    weatherData.registerObserver(forecastDisplay);

    weatherData.setMeasurements(80, 65, 30.4);
    weatherData.setMeasurements(82, 70, 29.2);
    weatherData.setMeasurements(78, 90, 29.2);

    return 0;
}