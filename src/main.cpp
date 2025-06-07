/**
 * @file main.cpp
 * @brief Main program for numerical differential equation solver
 * @author Prathamesh Khade
 * @date 2025-06-07
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include <chrono>
#include <thread>

#include "NumericalMethod.h"
#include "Euler.h"
#include "ModifiedEuler.h"
#include "RungeKutta2.h"
#include "RungeKutta4.h"
#include "AdamsBashforth.h"
#include "Utility.h"

/**
 * @brief Main function
 * @return 0 on successful execution
 */
int main() {
    // Welcome message
    Utility::clearScreen();
    std::cout << "===============================================" << std::endl;
    std::cout << "  Numerical Differential Equation Solver v2.0  " << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "           By Prathamesh Khade                 " << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "\nThis program implements various numerical methods for solving differential equations." << std::endl;
    std::cout << "The default equation is: dy/dx = x + y" << std::endl;
    std::cout << "To solve a different equation, modify the differentialFunction in the source code." << std::endl;

    // Get input parameters
    double x0, y0, xTarget, stepSize;
    std::cout << "\nEnter initial conditions and parameters:" << std::endl;
    
    std::cout << "Initial x (x0) = ";
    std::cin >> x0;
    
    std::cout << "Initial y (y0) = ";
    std::cin >> y0;
    
    std::cout << "Target x = ";
    std::cin >> xTarget;
    
    std::cout << "Step size (h) = ";
    std::cin >> stepSize;
    
    // Options for analysis
    bool compareWithExact = false;
    bool saveResults = false;
    bool runComparison = false;
    
    std::cout << "\nAdditional options:" << std::endl;
    
    std::cout << "Compare with exact solution? (1 for yes, 0 for no): ";
    std::cin >> compareWithExact;
    
    std::cout << "Save results to CSV files? (1 for yes, 0 for no): ";
    std::cin >> saveResults;
    
    std::cout << "Run comparison of all methods? (1 for yes, 0 for no): ";
    std::cin >> runComparison;
    
    // Method selection
    int option;
    std::cout << "\nWhich method do you want to perform?" << std::endl;
    std::cout << "1. Euler's Method" << std::endl;
    std::cout << "2. Modified Euler's Method (Heun's Method)" << std::endl;
    std::cout << "3. 2nd Order Runge-Kutta Method" << std::endl;
    std::cout << "4. 4th Order Runge-Kutta Method" << std::endl;
    std::cout << "5. Adams-Bashforth Method" << std::endl;
    std::cout << "6. All Methods (for comparison)" << std::endl;
    std::cout << "Enter your choice (1-6): ";
    std::cin >> option;
    
    // Vector to store all methods if comparison is requested
    std::vector<NumericalMethod*> methods;
    
    // Execute the selected method
    try {
        switch (option) {
            case 1: {
                EulersMethod euler;
                euler.setParameters(x0, y0, xTarget, stepSize);
                euler.setCompareExact(compareWithExact);
                euler.solve();
                
                if (saveResults) {
                    euler.saveToCSV("euler_results.csv");
                }
                
                if (runComparison) {
                    methods.push_back(new EulersMethod());
                }
                break;
            }
            
            case 2: {
                ModifiedEulersMethod modifiedEuler;
                modifiedEuler.setParameters(x0, y0, xTarget, stepSize);
                modifiedEuler.setCompareExact(compareWithExact);
                modifiedEuler.solve();
                
                if (saveResults) {
                    modifiedEuler.saveToCSV("modified_euler_results.csv");
                }
                
                if (runComparison) {
                    methods.push_back(new ModifiedEulersMethod());
                }
                break;
            }
            
            case 3: {
                RungeKutta2 rk2;
                rk2.setParameters(x0, y0, xTarget, stepSize);
                rk2.setCompareExact(compareWithExact);
                rk2.solve();
                
                if (saveResults) {
                    rk2.saveToCSV("rk2_results.csv");
                }
                
                if (runComparison) {
                    methods.push_back(new RungeKutta2());
                }
                break;
            }
            
            case 4: {
                RungeKutta4 rk4;
                rk4.setParameters(x0, y0, xTarget, stepSize);
                rk4.setCompareExact(compareWithExact);
                rk4.solve();
                
                if (saveResults) {
                    rk4.saveToCSV("rk4_results.csv");
                }
                
                if (runComparison) {
                    methods.push_back(new RungeKutta4());
                }
                break;
            }
            
            case 5: {
                AdamsBashforth adamsBashforth;
                adamsBashforth.setParameters(x0, y0, xTarget, stepSize);
                adamsBashforth.setCompareExact(compareWithExact);
                adamsBashforth.solve();
                
                if (saveResults) {
                    adamsBashforth.saveToCSV("adams_bashforth_results.csv");
                }
                
                if (runComparison) {
                    methods.push_back(new AdamsBashforth());
                }
                break;
            }
            
            case 6: {
                // Run all methods
                methods.push_back(new EulersMethod());
                methods.push_back(new ModifiedEulersMethod());
                methods.push_back(new RungeKutta2());
                methods.push_back(new RungeKutta4());
                methods.push_back(new AdamsBashforth());
                
                // Set parameters and solve
                for (auto& method : methods) {
                    method->setParameters(x0, y0, xTarget, stepSize);
                    method->setCompareExact(compareWithExact);
                    method->setVerbose(false);
                    method->solve();
                    
                    if (saveResults) {
                        method->saveToCSV(method->getMethodName() + "_results.csv");
                    }
                }
                
                // Compare all methods
                Utility::compareAllMethods(methods);
                break;
            }
            
            default: {
                std::cout << "\nInvalid option! Please choose a number between 1 and 6." << std::endl;
                break;
            }
        }
        
        // Run comparison if requested and not already done
        if (runComparison && option != 6 && !methods.empty()) {
            // Set parameters and solve for all methods
            for (auto& method : methods) {
                method->setParameters(x0, y0, xTarget, stepSize);
                method->setCompareExact(compareWithExact);
                method->setVerbose(false);
                method->solve();
            }
            
            // Compare results
            Utility::compareAllMethods(methods);
        }
        
        // Clean up
        for (auto& method : methods) {
            delete method;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    // Prompt to exit
    std::cout << "\nPress Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    
    return 0;
}