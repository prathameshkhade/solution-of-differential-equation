/**
 * @file Utility.cpp
 * @brief Implementation of utility functions
 * @author Prathamesh Khade
 * @date 2025-06-07
 */

#include "Utility.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>

void Utility::compareAllMethods(const std::vector<NumericalMethod*>& methods) {
    std::cout << "\n=== Comparison of All Methods ===" << std::endl;
    std::cout << std::fixed << std::setprecision(4);
    std::cout << std::left << std::setw(30) << "Method" 
             << std::setw(25) << "Result" 
             << std::setw(25) << "Exact Solution" 
             << std::setw(25) << "Absolute Error" 
             << std::endl;
    std::cout << std::string(105, '-') << std::endl;
    
    double exact = exactSolution(methods[0]->getXValues().back());
    // Round to 4 decimal places
    exact = std::round(exact * 10000.0) / 10000.0;
    
    for (const auto& method : methods) {
        double result = method->getResult();
        // Round to 4 decimal places
        result = std::round(result * 10000.0) / 10000.0;
        double error = std::abs(exact - result);
        // Round to 4 decimal places
        error = std::round(error * 10000.0) / 10000.0;
        
        std::cout << std::left << std::setw(30) << method->getMethodName()
                 << std::setw(25) << result
                 << std::setw(25) << exact
                 << std::setw(25) << error
                 << std::endl;
    }
}

void Utility::clearScreen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

void Utility::promptToContinue() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}