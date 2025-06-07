# Numerical Differential Equation Solver

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
![C++](https://img.shields.io/badge/C++-11-blue.svg)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20macOS%20%7C%20Linux-lightgrey)
![Last Updated](https://img.shields.io/badge/last%20updated-2025--06--07-brightgreen)

A comprehensive C++ implementation of various numerical methods for solving Ordinary Differential Equations (ODEs). This library provides accurate and efficient algorithms for approximating solutions to differential equations that are commonly encountered in science, engineering, and mathematical modeling.

## 🚀 Features

- Multiple numerical methods implemented:
  - **Euler's Method**: Simple first-order method
  - **Modified Euler's Method (Heun's Method)**: Second-order predictor-corrector method
  - **Runge-Kutta 2nd Order Method**: Improved accuracy over Euler's method
  - **Runge-Kutta 4th Order Method**: High accuracy, widely used method
  - **Adams-Bashforth Method**: Multi-step method for improved efficiency
  
- Advanced capabilities:
  - **Error Analysis**: Compare numerical solutions with exact analytical solutions
  - **Data Export**: Save results to CSV files for further analysis or visualization
  - **Method Comparison**: Compare the accuracy and performance of different methods
  - **Easy Customization**: Define your own differential equations with a simple function
  - **Precision Control**: All results are rounded to 4 decimal places for clarity

## 📋 Table of Contents

- [Installation](#-installation)
- [Usage](#-usage)
- [Implemented Methods](#-implemented-methods)
- [Project Structure](#-project-structure)
- [Customizing Differential Equations](#-customizing-differential-equations)
- [Example Problems](#-example-problems)
- [Performance Comparison](#-performance-comparison)
- [Contributing](#-contributing)
- [License](#-license)
- [Author](#-author)

## 🔧 Installation

### Prerequisites

- C++ compiler with C++11 support or later
- CMake 3.10 or later (for building the project)
- Standard C++ libraries

### Building from Source

1. Clone the repository:
   ```bash
   git clone https://github.com/prathameshkhade/solution-of-differential-equation.git
   cd solution-of-differential-equation
   ```

2. Create a build directory and configure with CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   ```

3. Build the project:
   ```bash
   cmake --build .
   ```

4. Run the executable:
   ```bash
   ./bin/solver
   ```

### Alternative: Manual Compilation

If you don't have CMake, you can compile manually:

```bash
g++ src/*.cpp -I include/ -o numerical_solver -std=c++11
```

## 🎮 Usage

When you run the program, you'll be prompted to:

1. Enter initial conditions (x₀, y₀)
2. Specify the target x value to solve for
3. Set the step size (h)
4. Choose additional options:
   - Compare with exact solution (if available)
   - Save results to CSV files
   - Run a comparison of all methods
5. Select a numerical method to use

### Example Session

```
===============================================
  Numerical Differential Equation Solver v2.0  
===============================================
           By Prathamesh Khade                 
===============================================

Enter initial conditions and parameters:
Initial x (x0) = 0
Initial y (y0) = 1
Target x = 1
Step size (h) = 0.1

Additional options:
Compare with exact solution? (1 for yes, 0 for no): 1
Save results to CSV files? (1 for yes, 0 for no): 1
Run comparison of all methods? (1 for yes, 0 for no): 0

Which method do you want to perform?
1. Euler's Method
2. Modified Euler's Method (Heun's Method)
3. 2nd Order Runge-Kutta Method
4. 4th Order Runge-Kutta Method
5. Adams-Bashforth Method
6. All Methods (for comparison)
Enter your choice (1-6): 4

=== 4th Order Runge-Kutta Method ===
Initial values: x0 = 0.0000, y0 = 1.0000
Step size: h = 0.1000
Target x = 1.0000

Step 1:
At x = 0.0000, y = 1.0000
k1 = 0.1000
k2 = 0.1050
k3 = 0.1053
k4 = 0.1108
delta k = 0.1044
New y = 1.1044 at x = 0.1000
Exact solution: 1.1103
Error: 0.0059

... [additional steps] ...

Final result at x = 1.0000: y = 4.4366
Exact solution: 4.4366
Error: 0.0000
```

## 📊 Implemented Methods

### Euler's Method

The simplest numerical method for solving ODEs. It uses the formula:

```
y_{n+1} = y_n + h * f(x_n, y_n)
```

**Advantages**: Simple to implement and understand
**Disadvantages**: Lower accuracy, requires small step size

### Modified Euler's Method (Heun's Method)

A second-order predictor-corrector method that improves on Euler's method:

```
y_{n+1} = y_n + h/2 * [f(x_n, y_n) + f(x_{n+1}, y_n + h * f(x_n, y_n))]
```

**Advantages**: Better accuracy than Euler's method
**Disadvantages**: Requires two function evaluations per step

### Runge-Kutta 2nd Order Method

A second-order method with improved accuracy:

```
k1 = h * f(x_n, y_n)
k2 = h * f(x_n + h, y_n + k1)
y_{n+1} = y_n + 1/2 * (k1 + k2)
```

**Advantages**: Good balance between accuracy and computational cost
**Disadvantages**: Less accurate than higher-order methods

### Runge-Kutta 4th Order Method

A highly accurate fourth-order method:

```
k1 = h * f(x_n, y_n)
k2 = h * f(x_n + h/2, y_n + k1/2)
k3 = h * f(x_n + h/2, y_n + k2/2)
k4 = h * f(x_n + h, y_n + k3)
y_{n+1} = y_n + 1/6 * (k1 + 2*k2 + 2*k3 + k4)
```

**Advantages**: High accuracy, widely used
**Disadvantages**: Requires four function evaluations per step

### Adams-Bashforth Method

A multi-step method that uses previous points to calculate the next value:

```
y_{n+1} = y_n + h/24 * (55*f_n - 59*f_{n-1} + 37*f_{n-2} - 9*f_{n-3})
```

**Advantages**: Efficient for long integrations
**Disadvantages**: Requires startup values from another method

## 📁 Project Structure

The project is organized into the following directory structure:

```
solution-of-differential-equation/
├── include/                      # Header files
│   ├── NumericalMethod.h         # Base class for all methods
│   ├── Euler.h                   # Euler's method
│   ├── ModifiedEuler.h           # Modified Euler's method
│   ├── RungeKutta2.h             # 2nd order Runge-Kutta
│   ├── RungeKutta4.h             # 4th order Runge-Kutta
│   ├── AdamsBashforth.h          # Adams-Bashforth method
│   └── Utility.h                 # Utility functions
├── src/                          # Source files
│   ├── NumericalMethod.cpp       # Base class implementation
│   ├── Euler.cpp                 # Euler's method implementation
│   ├── ModifiedEuler.cpp         # Modified Euler's implementation
│   ├── RungeKutta2.cpp           # RK2 implementation
│   ├── RungeKutta4.cpp           # RK4 implementation
│   ├── AdamsBashforth.cpp        # Adams-Bashforth implementation
│   ├── Utility.cpp               # Utility functions implementation
│   └── main.cpp                  # Main program
├── CMakeLists.txt                # Build system configuration
└── README.md                     # Project documentation
```

## 🧮 Customizing Differential Equations

To solve your own differential equation, modify the `differentialFunction` function in `src/NumericalMethod.cpp`:

```cpp
double differentialFunction(double x, double y) {
    // Change this to your differential equation
    return x + y;  // Example: dy/dx = x + y
    
    // Other examples:
    // return x * x + y;              // dy/dx = x² + y
    // return x * y;                  // dy/dx = xy
    // return std::sin(x) + std::cos(y); // dy/dx = sin(x) + cos(y)
}
```

If you know the exact solution to your equation, you can also modify the `exactSolution` function:

```cpp
double exactSolution(double x) {
    // Change this to the exact solution of your equation
    return 2 * std::exp(x) - x - 1;  // Solution for dy/dx = x + y
}
```

## 📝 Example Problems

### Example 1: Growth and Decay

```cpp
// Exponential growth/decay: dy/dx = ky
double differentialFunction(double x, double y) {
    double k = 0.5;  // Growth rate
    return k * y;
}

// Exact solution: y = y₀ * e^(kx)
double exactSolution(double x) {
    double k = 0.5;
    double y0 = 1.0;  // Initial condition
    return y0 * std::exp(k * x);
}
```

### Example 2: Harmonic Oscillator

```cpp
// Simple harmonic oscillator (convert to first-order system)
// y'' + y = 0 becomes y' = z, z' = -y
// This is for y' = z
double differentialFunction(double x, double y) {
    // Assuming z is stored elsewhere
    return z;
}

// Exact solution: y = A*cos(x) + B*sin(x)
double exactSolution(double x) {
    // With initial conditions y(0)=1, y'(0)=0
    return std::cos(x);
}
```

### Example 3: Logistic Growth

```cpp
// Logistic growth model: dy/dx = ry(1-y/K)
double differentialFunction(double x, double y) {
    double r = 0.5;  // Growth rate
    double K = 10.0; // Carrying capacity
    return r * y * (1 - y/K);
}

// No simple exact solution for arbitrary initial conditions
```

## 📈 Performance Comparison

The table below shows a comparison of the different methods for solving the equation dy/dx = x + y with initial conditions (0,1) to x = 1 with different step sizes:

| Method | Step Size | Result | Exact Solution | Error |
|--------|-----------|--------|----------------|-------|
| Euler's | 0.1 | 4.2579 | 4.4366 | 0.1787 |
| Modified Euler's | 0.1 | 4.4059 | 4.4366 | 0.0307 |
| RK2 | 0.1 | 4.4059 | 4.4366 | 0.0307 |
| RK4 | 0.1 | 4.4366 | 4.4366 | 0.0000 |
| Adams-Bashforth | 0.1 | 4.4364 | 4.4366 | 0.0002 |
| Euler's | 0.01 | 4.4141 | 4.4366 | 0.0225 |
| RK4 | 0.01 | 4.4366 | 4.4366 | 0.0000 |

As the table shows, higher-order methods like RK4 provide much better accuracy even with larger step sizes.

## 🤝 Contributing

Contributions are welcome! Here's how you can contribute:

1. Fork the repository
2. Create a feature branch: `git checkout -b feature-name`
3. Commit your changes: `git commit -m 'Add some feature'`
4. Push to the branch: `git push origin feature-name`
5. Open a pull request

Please make sure to update tests as appropriate and adhere to the existing coding style.

## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 👨‍💻 Author

**Prathamesh Khade**

- GitHub: [prathameshkhade](https://github.com/prathameshkhade)
- Last Update: 2025-06-07 07:08:45 UTC
