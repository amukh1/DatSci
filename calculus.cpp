#include <vector>
#include <memory>
#include <iostream>
#include <functional>

#include "calculus.h"

std::function<double(double)> Calc::diff(std::function<double(double)> f, double h) {
    return [f,h](double x) {
        return (f(x+h)-f(x))/h;
    };
}

std::function<double(std::vector<double>)> Calc::partialdiff(std::function<double(std::vector<double>)> f, double h, int i) {
    return [f,h,i,this](std::vector<double> x) {
        auto temp = [f,h,i,x](double x1) {
            std::vector<double> temp = x;
            temp[i] = x1;
            return f(temp);
        };
        return diff(temp,h)(x[i]);
    };
}

std::function<std::vector<double>(std::vector<double>)> Calc::grad(std::function<double(std::vector<double>)> f, double h) {
    return [this,f,h](std::vector<double> x) {
        std::vector<double> result;
        for (int i = 0; i < x.size(); i++) {
            result.push_back(partialdiff(f,h,i)(x));
        }
        return result;
    };
}