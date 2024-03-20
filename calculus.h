#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include <functional>

class Calc {
    public:
    // singlevarderiv
    std::function<double(double)> diff(std::function<double(double)> f, double h);
    // partialvarderiv
    std::function<double(std::vector<double>)> partialdiff(std::function<double(std::vector<double>)> f, double h, int i);
    // gradient
    std::function<std::vector<double>(std::vector<double>)> grad(std::function<double(std::vector<double>)> f, double h);
};