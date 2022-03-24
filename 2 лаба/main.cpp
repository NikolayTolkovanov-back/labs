#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

double myFunction(double x)
{
    return 4 * (1 + pow(x, 0.5)) * log(x) - 1;
}


double findRoot(double (*f)(double), double a, double b, double eps)
{
    double x;
    int steps = 0;

    while (fabs(myFunction(b)) > eps)
    {
        steps++;
        b = b - ((b - a) * f(b)) / (f(b) - f(a));
    }

    cout << "x: " << b << endl;
    cout << "f(x): " << f(b) << endl;
    cout << "eps: " << eps << endl;
    cout << "steps: " << steps << endl;
    steps = 0;

    return x;
}

double teoreticSteps(double a, double b, double eps)
{
    double k = (log(b - a) - log(eps)) / log(2) + 1;
    return floor(k);
}

int main()
{
    double a, b, eps = 0.0001;
    double x_array[100], y_array[100], intervals;
    double counter = 0.1;
    int start_time, end_time;

    for (int i = 0; i < 100; i++)
    {
        x_array[i] = counter;
        y_array[i] = myFunction(counter);
        // cout << "i: " << i << " x: " << x_array[i] << " y: " << y_array[i] << endl;
        counter += 0.1;
    }

    for (int j = 1; j < sizeof(y_array) / sizeof(y_array[0]); j++)
    {
        if (y_array[j - 1] * y_array[j] < 0)
        {
            a = x_array[j - 1];
            b = x_array[j];
            // cout << "INTERVALS: A: " << a << " B: " << b << endl;

            start_time = clock();
            findRoot(myFunction, a, b, eps);
            end_time = clock() - start_time;

            cout << "time: " << (float)end_time / CLOCKS_PER_SEC << endl;
            cout << "teoretic steps: " << teoreticSteps(a, b, eps) << "\n\n" << endl;
        }
    }
}