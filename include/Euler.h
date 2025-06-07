/**
 * @file Euler.h
 * @brief Euler's method for solving ODEs
 * @author Prathamesh Khade
 * @date 2025-06-07
 */

#ifndef EULER_H
#define EULER_H

#include "NumericalMethod.h"

/**
 * @class EulersMethod
 * @brief Implementation of Euler's method
 */
class EulersMethod : public NumericalMethod {
public:
    /**
     * @brief Constructor
     * @param diffFunc Function representing the differential equation
     */
    EulersMethod(std::function<double(double, double)> diffFunc = differentialFunction);
    
    /**
     * @brief Solve the differential equation using Euler's method
     */
    void solve() override;
    
    /**
     * @brief Get the method name
     * @return String "Euler's Method"
     */
    std::string getMethodName() const override;
};

#endif // EULER_H