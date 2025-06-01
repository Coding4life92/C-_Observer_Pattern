#pragma once
#include "iobserver.hpp"
#include "idisplay_element.hpp"
#include <iostream>

namespace ws
{
    class CurrentConditionDisplay : public IObserver, public IDisplayElement
    {
    public:
        void update(double temperature, double humidity, double pressure) override
        {
            m_temperature = temperature;
            m_humidity = humidity;
            display();
        }

        void display() override
        {
            std::cout << "Current conditions: " << m_temperature
                      << "F degrees and " << m_humidity << "% humidity" << std::endl;
        }

    private:
        double m_temperature{};
        double m_humidity{};
    };
} // namespace ws