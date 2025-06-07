/**
 * @file RungeKutta2.h
 * @brief 2nd order Runge-Kutta method for solving ODEs
 * @author Prathamesh Khade
 * @date 2025-06-07
 */

#ifndef RUNGE_KUTTA2_H
#define RUNGE_KUTTA2_H

#include "NumericalMethod.h"

/**
 * @class RungeKutta2
 * @brief Implementation of 2nd order Runge-Kutta method
 */
class RungeKutta2 : public NumericalMethod {
public:
    /**
     * @brief Constructor
     * @param diffFunc Function representing the differential equation
     */
    RungeKutta2(std::function<double(double, double)> diffFunc = differentialFunction);
    
    /**
     * @brief Solve the differential equation using 2nd order Runge-Kutta method
     */
    void solve() override;
    
    /**
     * @brief Get the method name
     * @return String "2nd Order Runge-Kutta Method"
     */
    std::string getMethodName() const override;
};

#endif // RUNGE_KUTTA2_H