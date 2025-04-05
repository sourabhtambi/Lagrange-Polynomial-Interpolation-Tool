#include <iostream>
#include <vector>
using namespace std;

double lagrangeInterpolation( vector<double> & x,vector<double> & y, double xi) {
    int n = x.size();
    double result = 0;

    // Iterate through each term in the Lagrange polynomial
    for (int i = 0; i < n; i++) {
        double term = y[i]; // Start with y[i]

        // Compute the Lagrange basis polynomial L_i(x)
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (xi - x[j]) / (x[i] - x[j]);
            }
        }

        result += term; // Sum up all terms
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n);
    vector<double> y(n);

    cout << "Enter x and y values : "<<endl;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }


    double xi;
    cout << "Enter the value of x to interpolate : ";
    cin >> xi;

    double final = lagrangeInterpolation(x, y, xi);
    cout << "Interpolated value at x = " << xi << " : " << final << endl;

    return 0;
}
