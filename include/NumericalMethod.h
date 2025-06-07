/**
 * @file NumericalMethod.h
 * @brief Base class for all numerical methods for solving differential equations
 * @author Prathamesh Khade
 * @date 2025-06-07
 */

#ifndef NUMERICAL_METHOD_H
#define NUMERICAL_METHOD_H

#include <vector>
#include <string>
#include <functional>

/**
 * @brief Default differential equation function: dy/dx = f(x,y)
 * @param x Independent variable
 * @param y Dependent variable
 * @return Value of the derivative at point (x,y)
 */
double differentialFunction(double x, double y);

/**
 * @brief Exact solution for testing accuracy (if known)
 * @param x Independent variable value
 * @return Exact solution at x
 */
double exactSolution(double x);

/**
 * @class NumericalMethod
 * @brief Abstract base class for all numerical methods
 */
class NumericalMethod {
protected:
    double x0, y0;      // Initial conditions
    double xTarget;     // Target x value
    double stepSize;    // Step size h
    int steps;          // Number of steps
    bool verbose;       // Flag for detailed output
    bool compareExact;  // Flag to compare with exact solution
    
    // Function pointer to the differential equation
    std::function<double(double, double)> diffFunction;
    
    // Store results for analysis and visualization
    std::vector<double> xValues;
    std::vector<double> yValues;
    
public:
    /**
     * @brief Constructor
     * @param diffFunc Function representing the differential equation
     */
    NumericalMethod(std::function<double(double, double)> diffFunc = differentialFunction);
    
    /**
     * @brief Virtual destructor
     */
    virtual ~NumericalMethod();
    
    /**
     * @brief Set the initial conditions and parameters
     * @param x0Val Initial x value
     * @param y0Val Initial y value
     * @param xTargetVal Target x value
     * @param stepSizeVal Step size h
     */
    void setParameters(double x0Val, double y0Val, double xTargetVal, double stepSizeVal);
    
    /**
     * @brief Enable/disable verbose output
     * @param isVerbose True for detailed output, false for minimal output
     */
    void setVerbose(bool isVerbose);
    
    /**
     * @brief Enable/disable comparison with exact solution
     * @param doCompare True to compare with exact solution
     */
    void setCompareExact(bool doCompare);
    
    /**
     * @brief Get the result at the target x
     * @return Approximated y value at target x
     */
    double getResult() const;
    
    /**
     * @brief Get all x values
     * @return Vector of x values
     */
    const std::vector<double>& getXValues() const;
    
    /**
     * @brief Get all y values
     * @return Vector of y values
     */
    const std::vector<double>& getYValues() const;
    
    /**
     * @brief Save results to a CSV file
     * @param filename Name of the file to save to
     */
    void saveToCSV(const std::string& filename) const;
    
    /**
     * @brief Calculate global truncation error if exact solution is available
     * @return Maximum absolute error
     */
    double calculateError() const;
    
    /**
     * @brief Pure virtual function to be implemented by all numerical methods
     */
    virtual void solve() = 0;
    
    /**
     * @brief Get the name of the method
     * @return String with the method name
     */
    virtual std::string getMethodName() const = 0;
};

#endif // NUMERICAL_METHOD_H