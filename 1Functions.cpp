#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double start = 0.1;
    double step = 0.4; 
    double x;

    for (int i = 0; i < 10; i++) {
        x = start + i * step;
        if (x == 0) { 
            cout << "x = 0: undefined" << endl;
        }
        else {
            cout << "sin(" << x << ")/" << x << " = " << sin(x) / x << endl;
        }
    }

    return 0;
}