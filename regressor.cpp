#include <vector>
#include <memory>
#include <iostream>
#include <functional>
#include <utility>
#include <cmath>

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

std::pair<std::vector<double>,double> Regressor::linearn(std::vector<std::vector<double>> A, int k) {
    // Matrix W: n-1 x n-1 matrix
    std::vector<double> w(A.size()-1, 0);
    // Vector b: n-1 vector
    double b = 0.0;

    auto f = [](std::vector<double> w, double b, std::vector<double> x) {
        double result = 0;
        for (int i = 0; i < w.size(); i++) {
            result += w[i]*x[i];
        }
        return result + b;
    };

    auto cost = [A,f](std::vector<double> W) {
        std::vector<double> w;
        double b;

        for(int i = 0; i<W.size()-1; i++) {
            w.push_back(W[i]);
        }
        b = W[W.size()-1];

        double result = 0;
        for(int i = 0; i<A[0].size(); i++) {
            std::vector<double> x;
            for(int j = 0; j<A[i].size()-1; j++) {
                x.push_back(A[j][i]);
            }
            result += std::pow(A[A.size()-1][i] - f(w,b,x), 2);
        }
        return result;
    };
    
    Calc handler;
    for(int i = 0; i<k; i++) {
        std::vector<double> C;
        for(int j = 0; j<w.size(); j++) {
            C.push_back(w[j]);
        }
        C.push_back(b);
        for(int j = 0; j<w.size(); j++) {
            handler.partialdiff(cost, 0.0001, j);
            // w[j] -= 0.01*handler.partialdiff(cost, 0.0001, j)(C);
        }
        // b -= 0.01*handler.partialdiff(cost, 0.0001, w.size()-1)(C);
    }
    return std::make_pair(w,b);
}