#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include <functional>
#include <utility>

#include "calculus.h"

class Regressor {
    public:
    std::pair<double, double> linear(std::vector<double> x, std::vector<double> y, int i);
    std::pair<std::vector<double>,double> linearn(std::vector<std::vector<double>> x, int i);
};