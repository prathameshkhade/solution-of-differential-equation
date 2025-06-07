/**
 * @file AdamsBashforth.h
 * @brief Adams-Bashforth method for solving ODEs
 * @author Prathamesh Khade
 * @date 2025-06-07
 */

#ifndef ADAMS_BASHFORTH_H
#define ADAMS_BASHFORTH_H

#include "NumericalMethod.h"

/**
 * @class AdamsBashforth
 * @brief Implementation of Adams-Bashforth method (multi-step method)
 */
class AdamsBashforth : public NumericalMethod {
public:
    /**
     * @brief Constructor
     * @param diffFunc Function representing the differential equation
     */
    AdamsBashforth(std::function<double(double, double)> diffFunc = differentialFunction);
    
    /**
     * @brief Solve the differential equation using Adams-Bashforth method
     */
    void solve() override;
    
    /**
     * @brief Get the method name
     * @return String "Adams-Bashforth Method"
     */
    std::string getMethodName() const override;
};

#endif // ADAMS_BASHFORTH_H