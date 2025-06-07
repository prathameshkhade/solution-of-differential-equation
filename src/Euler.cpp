/**
 * @file Euler.cpp
 * @brief Implementation of Euler's method
 * @author Prathamesh Khade
 * @date 2025-06-07
 */

#include "Euler.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

EulersMethod::EulersMethod(std::function<double(double, double)> diffFunc) 
    : NumericalMethod(diffFunc) {}

void EulersMethod::solve() {
    // Start with initial values (already in vectors)
    double x = x0;
    double y = y0;
    
    if (verbose) {
        std::cout << "\n=== Euler's Method ===" << std::endl;
        std::cout << "Initial values: x0 = " << std::fixed << std::setprecision(4) << x0 
                  << ", y0 = " << y0 << std::endl;
        std::cout << "Step size: h = " << stepSize << std::endl;
        std::cout << "Target x: " << xTarget << std::endl;
    }
    
    // Solve step by step
    for (int i = 0; i < steps; ++i) {
        // Calculate next values using Euler's formula: y_{n+1} = y_n + h * f(x_n, y_n)
        double slope = diffFunction(x, y);
        x += stepSize;
        y += stepSize * slope;
        
        // Round to 4 decimal places
        y = std::round(y * 10000.0) / 10000.0;
        
        // Store values
        xValues.push_back(x);
        yValues.push_back(y);
        
        if (verbose) {
            std::cout << "\nStep " << (i + 1) << ":" << std::endl;
            std::cout << "x = " << std::fixed << std::setprecision(4) << x 
                      << ", y = " << y << std::endl;
            
            if (compareExact) {
                double exact = exactSolution(x);
                // Round to 4 decimal places
                exact = std::round(exact * 10000.0) / 10000.0;
                double error = std::abs(exact - y);
                std::cout << "Exact solution: " << exact << std::endl;
                std::cout << "Error: " << std::fixed << std::setprecision(4) << error << std::endl;
            }
            
            // Add small delay for better user experience
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    
    if (verbose) {
        std::cout << "\nFinal result at x = " << std::fixed << std::setprecision(4) << xTarget 
                  << ": y = " << y << std::endl;
        
        if (compareExact) {
            double exact = exactSolution(xTarget);
            // Round to 4 decimal places
            exact = std::round(exact * 10000.0) / 10000.0;
            double error = std::abs(exact - y);
            std::cout << "Exact solution: " << exact << std::endl;
            std::cout << "Error: " << std::fixed << std::setprecision(4) << error << std::endl;
        }
    }
}

std::string EulersMethod::getMethodName() const {
    return "Euler's Method";
}