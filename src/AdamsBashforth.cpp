/**
 * @file AdamsBashforth.cpp
 * @brief Implementation of Adams-Bashforth method
 * @author Prathamesh Khade
 * @date 2025-06-07
 */

#include "AdamsBashforth.h"
#include "RungeKutta4.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

AdamsBashforth::AdamsBashforth(std::function<double(double, double)> diffFunc) 
    : NumericalMethod(diffFunc) {}

void AdamsBashforth::solve() {
    // For Adams-Bashforth, we need to use RK4 for the first 4 steps
    RungeKutta4 rk4(diffFunction);
    rk4.setVerbose(false);
    rk4.setParameters(x0, y0, x0 + 3 * stepSize, stepSize);
    rk4.solve();
    
    // Get the first 4 points from RK4
    xValues = rk4.getXValues();
    yValues = rk4.getYValues();
    
    // Calculate the remaining points using Adams-Bashforth
    double x = xValues.back();
    double y = yValues.back();
    
    if (verbose) {
        std::cout << "\n=== Adams-Bashforth Method ===" << std::endl;
        std::cout << "Initial values: x0 = " << std::fixed << std::setprecision(4) << x0 
                  << ", y0 = " << y0 << std::endl;
        std::cout << "Step size: h = " << stepSize << std::endl;
        std::cout << "Target x: " << xTarget << std::endl;
        std::cout << "Using RK4 for first 4 steps" << std::endl;
        
        for (size_t i = 0; i < xValues.size(); ++i) {
            std::cout << "Initial point " << i << ": x = " << std::fixed << std::setprecision(4) 
                      << xValues[i] << ", y = " << yValues[i] << std::endl;
        }
    }
    
    // Store the function values at the last 4 points
    std::vector<double> fValues;
    for (int i = 0; i < 4; ++i) {
        fValues.push_back(diffFunction(xValues[xValues.size() - 4 + i], yValues[yValues.size() - 4 + i]));
    }
    
    // Continue from the 4th step to the end
    for (int i = 4; i <= steps; ++i) {
        if (verbose) {
            std::cout << "\nStep " << i << ":" << std::endl;
        }
        
        // Adams-Bashforth 4-step formula
        double yNext = yValues.back() + stepSize * (
            55.0 * fValues[3] - 
            59.0 * fValues[2] + 
            37.0 * fValues[1] - 
            9.0 * fValues[0]
        ) / 24.0;
        
        // Round to 4 decimal places
        yNext = std::round(yNext * 10000.0) / 10000.0;
        
        // Update x and y
        x += stepSize;
        y = yNext;
        
        // Store values
        xValues.push_back(x);
        yValues.push_back(y);
        
        // Update function values
        for (int j = 0; j < 3; ++j) {
            fValues[j] = fValues[j + 1];
        }
        fValues[3] = diffFunction(x, y);
        
        if (verbose) {
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

std::string AdamsBashforth::getMethodName() const {
    return "Adams-Bashforth Method";
}