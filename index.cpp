#include <vector>
#include <memory>
#include <iostream>
#include <typeinfo>
#include <functional>
#include <utility>

#include "calculus.h"
#include "regressor.h"

int main() {
    auto sq = [](double x) {
        return x*x;
    };
    
    auto sqM = [](std::vector<double> x) {
        double result;
        for (auto i : x) {
            result += i*i;
        }
        return result;
    };

    Calc handler;
    // std::cout << handler.diff(sq, 0.0001)(5) << std::endl;
    // std::cout << handler.partialdiff(sqM, 0.001, 1)({1,2}) << std::endl;
    // std::cout << handler.grad(sqM, 0.0001)({1,2,3})[0] << std::endl;
    // std::vector<double> x = {1,2,3,4,5};
    // std::vector<double> y = {2,3,4,5,6};
    // Regressor model;
    // std::pair<double, double> result = model.linear(x,y,1000);
    // std::cout << result.first << "x + " << result.second << std::endl;
    std::vector<std::vector<double>> x = {{1,2,3,4,5,6},{2,3,4,5,6,7}}; // ,{3,4,5,6,7,8},{4,5,6,7,8,9},{5,6,7,8,9,10}
    Regressor model;
    std::pair<std::vector<double>,double> result = model.linearn(x,1000);
    for (auto i : result.first) {
        std::cout << i << "x + ";
    }
    std::cout << "+ " << result.second << std::endl;
}