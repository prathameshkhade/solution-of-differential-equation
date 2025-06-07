/**
 * @file NumericalMethod.cpp
 * @brief Implementation of the NumericalMethod base class
 * @author Prathamesh Khade
 * @date 2025-06-07
 */

#include "NumericalMethod.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <stdexcept>

// Implementation of default differential equation function
double differentialFunction(double x, double y) {
    // Example: dy/dx = x + y
    return x + y;
    
    // Uncomment and modify as needed for different equations:
    // return x * x + y;              // dy/dx = x² + y
    // return x * y;                  // dy/dx = xy
    // return std::sin(x) + std::cos(y); // dy/dx = sin(x) + cos(y)
}

// Implementation of exact solution for testing
double exactSolution(double x) {
    // Example: solution for dy/dx = x + y is y = 2e^x - x - 1
    return 2 * std::exp(x) - x - 1;
}

NumericalMethod::NumericalMethod(std::function<double(double, double)> diffFunc) 
    : diffFunction(diffFunc), verbose(true), compareExact(false) {}

NumericalMethod::~NumericalMethod() {}

void NumericalMethod::setParameters(double x0Val, double y0Val, double xTargetVal, double stepSizeVal) {
    x0 = x0Val;
    y0 = y0Val;
    xTarget = xTargetVal;
    stepSize = stepSizeVal;
    
    // Calculate number of steps
    steps = static_cast<int>((xTarget - x0) / stepSize + 0.5);
    
    // Pre-allocate memory for results
    xValues.reserve(steps + 1);
    yValues.reserve(steps + 1);
    
    // Store initial values
    xValues.push_back(x0);
    yValues.push_back(y0);
}

void NumericalMethod::setVerbose(bool isVerbose) {
    verbose = isVerbose;
}

void NumericalMethod::setCompareExact(bool doCompare) {
    compareExact = doCompare;
}

double NumericalMethod::getResult() const {
    if (yValues.empty()) {
        throw std::runtime_error("Method has not been solved yet");
    }
    return yValues.back();
}

const std::vector<double>& NumericalMethod::getXValues() const {
    return xValues;
}

const std::vector<double>& NumericalMethod::getYValues() const {
    return yValues;
}

void NumericalMethod::saveToCSV(const std::string& filename) const {
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }
    
    // Write header
    file << "Step,x,y";
    if (compareExact) {
        file << ",exact,error";
    }
    file << std::endl;
    
    // Write data with 4 decimal precision
    file << std::fixed << std::setprecision(4);
    
    for (size_t i = 0; i < xValues.size(); ++i) {
        file << i << "," << xValues[i] << "," << yValues[i];
        
        if (compareExact) {
            double exact = exactSolution(xValues[i]);
            double error = std::abs(exact - yValues[i]);
            file << "," << exact << "," << error;
        }
        
        file << std::endl;
    }
    
    file.close();
    
    if (verbose) {
        std::cout << "Results saved to " << filename << std::endl;
    }
}

double NumericalMethod::calculateError() const {
    if (xValues.empty() || yValues.empty()) {
        throw std::runtime_error("Method has not been solved yet");
    }
    
    double maxError = 0.0;
    
    for (size_t i = 0; i < xValues.size(); ++i) {
        double exact = exactSolution(xValues[i]);
        double error = std::abs(exact - yValues[i]);
        maxError = std::max(maxError, error);
    }
    
    return maxError;
}