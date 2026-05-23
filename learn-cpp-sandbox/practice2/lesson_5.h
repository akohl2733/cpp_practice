#pragma once

#include <string_view>
#include <string>
#include <utility>

double returnWhatever() {
    constexpr double gravity {9.8};
    constexpr int speed {14};

    return speed * gravity;
}

void getWholeName()
{
    std::string name{};
    std::string color{};

    std::cout << "Enter your full name: " << std::endl;
    std::getline(std::cin >> std::ws, name);

    std::cout << "Please enter your favorite color: " << std::endl;
    std::getline(std::cin >> std::ws, color);

    std::cout << "Your name is " << name << " and your favorite color is " << color << std::endl;
}

int getStrLen(std::string_view s)
{
    return s.length();
}

void getRectangeStats(double h, double w, double& area, double& perimeter)
{
    area = h * w;
    perimeter = (2*h) + (2*w);
}

std::pair<double, double> getRectangeStatsRedux(double h, double w)
{
    double area = h * w;
    double perimater = h*2 + w*2;
    
    return {area, perimater};
}