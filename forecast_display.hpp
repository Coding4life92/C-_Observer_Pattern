#pragma once
#include "iobserver.hpp"
#include "idisplay_element.hpp"
#include <iostream>

namespace ws
{
    class ForecastDisplay : public IObserver, public IDisplayElement
    {
    public:
        void update(double temperature, double humidity, double pressure) override
        {
            m_lastPressure = m_currentPressure;
            m_currentPressure = pressure;
            display();
        }

        void display() override
        {
            std::cout << "Forcast: ";
            if (m_currentPressure > m_lastPressure)
            {
                std::cout << "Improving weather on the way!" << std::endl;
            }
            else if (m_currentPressure == m_lastPressure)
            {
                std::cout << "Same weather ahead!" << std::endl;
            }
            else
            {
                std::cout << "Cooler, rainy weather ahead!" << std::endl;
            }
        }

    private:
        double m_currentPressure = 29.92;
        double m_lastPressure{};
    };
} // namespace ws