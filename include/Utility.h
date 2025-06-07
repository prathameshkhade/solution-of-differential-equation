/**
 * @file Utility.h
 * @brief Utility functions for the numerical methods
 * @author Prathamesh Khade
 * @date 2025-06-07
 */

#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
#include "NumericalMethod.h"

/**
 * @class Utility
 * @brief Utility class for common functions
 */
class Utility {
public:
    /**
     * @brief Compare all methods and print a summary
     * @param methods Vector of numerical methods
     */
    static void compareAllMethods(const std::vector<NumericalMethod*>& methods);
    
    /**
     * @brief Clear the console screen
     */
    static void clearScreen();
    
    /**
     * @brief Prompt user to continue
     */
    static void promptToContinue();
};

#endif // UTILITY_H