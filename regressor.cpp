#include <vector>
#include <memory>
#include <iostream>
#include <functional>

#include "calculus.h"
#include "regressor.h"          

std::pair<double, double> Regressor::linear(std::vector<double> x, std::vector<double> y, int k) {
    double w, b;
    auto cost = [x,y](std::vector<double> z) {
        double result = 0;
        double w = z[0];
        double b = z[1];
        for (int i = 0; i < x.size(); i++) {
            result += (y[i] - (w*x[i] + b))*(y[i] - (w*x[i] + b));
        }
        return result;
    };

    Calc handler;
    for(int i = 0; i<k; i++) {
        w -= 0.01*handler.partialdiff(cost, 0.0001, 0)({w,b});
        b -= 0.01*handler.partialdiff(cost, 0.0001, 1)({w,b});
    }
    return std::make_pair(w,b);
}