/**
 * @file ModifiedEuler.h
 * @brief Modified Euler's method (Heun's Method) for solving ODEs
 * @author Prathamesh Khade
 * @date 2025-06-07
 */

#ifndef MODIFIED_EULER_H
#define MODIFIED_EULER_H

#include "NumericalMethod.h"

/**
 * @class ModifiedEulersMethod
 * @brief Implementation of Modified Euler's method (Heun's Method)
 */
class ModifiedEulersMethod : public NumericalMethod {
public:
    /**
     * @brief Constructor
     * @param diffFunc Function representing the differential equation
     */
    ModifiedEulersMethod(std::function<double(double, double)> diffFunc = differentialFunction);
    
    /**
     * @brief Solve the differential equation using Modified Euler's method
     */
    void solve() override;
    
    /**
     * @brief Get the method name
     * @return String "Modified Euler's Method"
     */
    std::string getMethodName() const override;
};

#endif // MODIFIED_EULER_H