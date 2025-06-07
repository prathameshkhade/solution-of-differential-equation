/**
 * @file RungeKutta4.cpp
 * @brief Implementation of 4th order Runge-Kutta method
 * @author Prathamesh Khade
 * @date 2025-06-07
 */

#include "RungeKutta4.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

RungeKutta4::RungeKutta4(std::function<double(double, double)> diffFunc) 
    : NumericalMethod(diffFunc) {}

void RungeKutta4::solve() {
    // Start with initial values (already in vectors)
    double x = x0;
    double y = y0;
    
    if (verbose) {
        std::cout << "\n=== 4th Order Runge-Kutta Method ===" << std::endl;
        std::cout << "Initial values: x0 = " << std::fixed << std::setprecision(4) << x0 
                  << ", y0 = " << y0 << std::endl;
        std::cout << "Step size: h = " << stepSize << std::endl;
        std::cout << "Target x: " << xTarget << std::endl;
    }
    
    // Solve step by step
    for (int i = 0; i < steps; ++i) {
        if (verbose) {
            std::cout << "\nStep " << (i + 1) << ":" << std::endl;
            std::cout << "At x = " << std::fixed << std::setprecision(4) << x 
                      << ", y = " << y << std::endl;
        }
        
        // Calculate k1, k2, k3, and k4
        double k1 = stepSize * diffFunction(x, y);
        double k2 = stepSize * diffFunction(x + 0.5 * stepSize, y + 0.5 * k1);
        double k3 = stepSize * diffFunction(x + 0.5 * stepSize, y + 0.5 * k2);
        double k4 = stepSize * diffFunction(x + stepSize, y + k3);
        
        // Calculate delta k and next y
        double deltaK = (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
        
        // Round to 4 decimal places
        k1 = std::round(k1 * 10000.0) / 10000.0;
        k2 = std::round(k2 * 10000.0) / 10000.0;
        k3 = std::round(k3 * 10000.0) / 10000.0;
        k4 = std::round(k4 * 10000.0) / 10000.0;
        deltaK = std::round(deltaK * 10000.0) / 10000.0;
        
        // Update values
        x += stepSize;
        y += deltaK;
        
        // Round to 4 decimal places
        y = std::round(y * 10000.0) / 10000.0;
        
        // Store values
        xValues.push_back(x);
        yValues.push_back(y);
        
        if (verbose) {
            std::cout << "k1 = " << k1 << std::endl;
            std::cout << "k2 = " << k2 << std::endl;
            std::cout << "k3 = " << k3 << std::endl;
            std::cout << "k4 = " << k4 << std::endl;
            std::cout << "delta k = " << deltaK << std::endl;
            std::cout << "New y = " << y << " at x = " << std::fixed << std::setprecision(4) << x << std::endl;
            
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

std::string RungeKutta4::getMethodName() const {
    return "4th Order Runge-Kutta Method";
}