#include <bits/stdc++.h>
#include <conio.h>
#define e 2.718281
#define pi 3.141592 
using namespace std;

inline float f(float x, float y) {
    return  0;
}

class Input { 
    int n;
    float x0, y0, h, X;

    public:
        Input() {
            cout << "x = ";
            cin >> X;
            cout << "x0 = ";
            cin >> x0;
            cout << "y0 = ";
            cin >> y0;
            cout << "h = ";
            cin >> h;
        }

        friend class Eulers;
        friend class EulersModified;
        friend class RK2;
        friend class RK4;  
};

class Eulers {
    public: 
        float calculation(Input &eu) {
            eu.n = (eu.X-eu.x0)/eu.h;
            float x[(int) eu.n], y[(int) eu.n];
            x[0] = eu.x0;
            y[0] = eu.y0;

            // Values of x 
            for (int i=1; i<=eu.n; i++) {
                x[i] = x[i-1] + eu.h; 
            }
            
            for(int i=0; i<eu.n; i++) {
                y[i+1] = y[i] + ( eu.h * f(x[i], y[i]) );

                _sleep(545);
                cout << endl << "Step " << i+1 << ": " << endl;
                cout << "At x" << i+1 << " = " << x[i+1] << "\t" << "y" << i+1 << " = " << y[i+1] << endl;
            }

            _sleep(1000);
            cout << endl << "Answer is " << y[(int) eu.n];
        }
};

class EulersModified {
    public: 
        float calculation(Input &em) {
            em.n = (em.X-em.x0)/em.h;
            
            // Declaration of Arrays for the values of x and y...........
            float x[em.n], Y[em.n], y[em.n];     // x[n] --> values of x; Y[n] --> values of Euler's Formula; y[n] --> values for Modified Euler's Formula;

            // Initialization of values...........
            x[0] = em.x0;
            Y[0] = em.y0;

            // Initialization of values of x........
            for (int i=1; i<=em.n; i++) {
                x[i] = x[i-1] + em.h;
            }

            // Euler's Formula.......
            for (int i=0; i<em.n; i++) {
                Y[i+1] = Y[i] + ( em.h * f(x[i], Y[i]) );
            }

            // Modified Euler's Formula.......
            for (int i=0; i<em.n; i++) {
                y[i+1] = Y[i] +( (0.5*em.h) * ( f(x[i], Y[i]) + f(x[i+1], Y[i+1]) ) );

                _sleep(545);
                cout << endl << "Step" << i+1 << ": " << endl;
                cout << "At x" << i+1 << " = " << x[i+1] << endl;
                cout << "By Euler's Formula, " << "y*" << i+1 << " = " << Y[i+1] << endl; 
                cout << "By Modified Euler's Formula, " << "y" << i+1 << " = " << y[i+1] << endl; 
            }

            // Printing the final Answer....
            _sleep(1000);
            cout << endl << endl << "Answer is " << y[em.n];
        }
};  

class RK2 {
    public: 
        float calculation(Input &rk2) {
            rk2.n = (rk2.X-rk2.x0)/rk2.h;

            // Runge Kutta 2nd order Formula.........
            for (int i=1; i<=rk2.n; i++) {
                // Printing the initial values...........
                cout << endl << "Step " << i << ": " << " At x" << i-1 << " = " << rk2.x0 << "  y" << i-1 << " = " << rk2.y0 << endl;

                // Formula of RK 2nd order method............
                float k1 = rk2.h * f(rk2.x0, rk2.y0);
                float k2 = rk2.h * f(rk2.x0+rk2.h, rk2.y0+k1);
                float del_k = 0.5 * (k1 + k2);
                float ans = rk2.y0 + del_k;

                // Printing the values.........
                _sleep(545);
                cout << "k1 = " << k1 << "\nk2 = " << k2 << "\ndelta k = " << del_k << endl;
                cout << "y" << i << " = " << ans << "   at x" << i << " = " << rk2.x0+rk2.h << endl;

                // Updating the values for next itteration........
                rk2.x0 += rk2.h;
                rk2.y0 = ans;
            }

            // Printing the final Answer...................
            _sleep(1000);
            cout << endl << endl << "Prss any key to exit....";
        }
};

class RK4 {
    public: 
        float calculation(Input &rk4) {
            rk4.n = (rk4.X-rk4.x0)/rk4.h;

            // Runge Kutta 4th order Formula.........
            for (int i=1; i<=rk4.n; i++) {
                // Printing the initial values...........
                cout << endl << "Step " << i << ": " << " At x" << i-1 << " = " << rk4.x0 << "  y" << i-1 << " = " << rk4.y0 << endl;

                // Formula of RK method....................
                float k1 = rk4.h * f(rk4.x0, rk4.y0);
                float k2 = rk4.h * f(rk4.x0+(rk4.h/2), rk4.y0+(k1/2));
                float k3 = rk4.h * f(rk4.x0+(rk4.h/2), rk4.y0+(k2/2));
                float k4 = rk4.h * f(rk4.x0+rk4.h, rk4.y0+k3);
                float del_k = (k1 + 2*k2 + 2*k3 + k4)/6;
                float ans = rk4.y0 + del_k;

                // Printing the values...............
                _sleep(545);
                cout << "k1 = " << k1 << "\nk2 = " << k2 << "\nk3 = " << k3 << "\nk4 = " << k4 << "\ndelta k = " << del_k << endl;
                cout << "y" << i << " = " << ans << "   at x" << i << " = " << rk4.x0+rk4.h << endl;

                // Updating the values for next itteration...................
                rk4.x0 += rk4.h;
                rk4.y0 = ans;
            }

            // Printing the final Answer...................
            _sleep(1000);
            cout << endl << endl << "Prss any key to exit.....";
        }
};

int main() 
{
    Input i;
    int option;
    cout << endl << "Which method you want to perform....." << endl;
    cout << "1. Euler's Method" << endl;
    cout << "2. Euler's Modified Method " << endl;
    cout << "3. Runge Kutta 2nd Order Method " << endl;
    cout << "4. Runge Kutta 4th Order Method " << endl;
    cout << "choose: ";
    cin >> option;

    switch (option) {
        case 1:  {   
            Eulers eu;
            eu.calculation(i);
            break;
        }
        
        case 2: {
            EulersModified em;
            em.calculation(i);
            break;
        }

        case 3:  {   
            RK2 rk2;
            rk2.calculation(i);
            break;
        }
        
        case 4: {
            RK4 rk4;
            rk4.calculation(i);
            break;
        }
        
        default:    {
            cout << endl << "Choose correct option!!!";
            break;
        }
    }
    
    getch();
    return 0;
}
