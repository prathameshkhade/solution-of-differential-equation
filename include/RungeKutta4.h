/**
 * @file RungeKutta4.h
 * @brief 4th order Runge-Kutta method for solving ODEs
 * @author Prathamesh Khade
 * @date 2025-06-07
 */

#ifndef RUNGE_KUTTA4_H
#define RUNGE_KUTTA4_H

#include "NumericalMethod.h"

/**
 * @class RungeKutta4
 * @brief Implementation of 4th order Runge-Kutta method
 */
class RungeKutta4 : public NumericalMethod {
public:
    /**
     * @brief Constructor
     * @param diffFunc Function representing the differential equation
     */
    RungeKutta4(std::function<double(double, double)> diffFunc = differentialFunction);
    
    /**
     * @brief Solve the differential equation using 4th order Runge-Kutta method
     */
    void solve() override;
    
    /**
     * @brief Get the method name
     * @return String "4th Order Runge-Kutta Method"
     */
    std::string getMethodName() const override;
};

#endif // RUNGE_KUTTA4_H