#pragma once
#include "iobserver.hpp"
#include "idisplay_element.hpp"
#include <iostream>
#include <limits>

namespace ws
{
    class StatisticsDisplay : public IObserver, public IDisplayElement
    {
    public:
        void update(double temperature, double humidity, double pressure) override
        {
            ++m_numberOfReadings;
            m_avgTemperature = (m_avgTemperature * (m_numberOfReadings - 1) + temperature) / m_numberOfReadings;
            m_maxTemperature = std::max(m_maxTemperature, temperature);
            m_minTemperatire = std::min(m_minTemperatire, temperature);
            display();
        }

        void display() override
        {
            std::cout << "Avg/Max/Min temperature = " << m_avgTemperature << "."
                      << m_maxTemperature << "/" << m_minTemperatire << std::endl;
        }

    private:
        int m_numberOfReadings{};
        double m_maxTemperature = std::numeric_limits<double>::min();
        double m_minTemperatire = std::numeric_limits<double>::max();
        double m_avgTemperature{};
    };
}; // namespace ws