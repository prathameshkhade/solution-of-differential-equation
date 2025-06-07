/**
 * @file ModifiedEuler.cpp
 * @brief Implementation of Modified Euler's method (Heun's Method)
 * @author Prathamesh Khade
 * @date 2025-06-07
 */

#include "ModifiedEuler.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

ModifiedEulersMethod::ModifiedEulersMethod(std::function<double(double, double)> diffFunc) 
    : NumericalMethod(diffFunc) {}

void ModifiedEulersMethod::solve() {
    // Start with initial values (already in vectors)
    double x = x0;
    double y = y0;
    
    if (verbose) {
        std::cout << "\n=== Modified Euler's Method (Heun's Method) ===" << std::endl;
        std::cout << "Initial values: x0 = " << std::fixed << std::setprecision(4) << x0 
                  << ", y0 = " << y0 << std::endl;
        std::cout << "Step size: h = " << stepSize << std::endl;
        std::cout << "Target x: " << xTarget << std::endl;
    }
    
    // Solve step by step
    for (int i = 0; i < steps; ++i) {
        // Step 1: Calculate predictor (Euler's method)
        double k1 = diffFunction(x, y);
        double xNext = x + stepSize;
        double yPredictor = y + stepSize * k1;
        
        // Step 2: Calculate corrector
        double k2 = diffFunction(xNext, yPredictor);
        double yCorrector = y + stepSize * 0.5 * (k1 + k2);
        
        // Round to 4 decimal places
        yPredictor = std::round(yPredictor * 10000.0) / 10000.0;
        yCorrector = std::round(yCorrector * 10000.0) / 10000.0;
        
        // Update values
        x = xNext;
        y = yCorrector;
        
        // Store values
        xValues.push_back(x);
        yValues.push_back(y);
        
        if (verbose) {
            std::cout << "\nStep " << (i + 1) << ":" << std::endl;
            std::cout << "x = " << std::fixed << std::setprecision(4) << x << std::endl;
            std::cout << "Predictor (Euler): y* = " << yPredictor << std::endl;
            std::cout << "Corrector (Modified): y = " << y << std::endl;
            
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

std::string ModifiedEulersMethod::getMethodName() const {
    return "Modified Euler's Method";
}