// f(x) = cos(x^2 * cos(x)); a = 5; b = 7; n = 4, 5, 7
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

double myFunction(double x)
{
    return cos(pow(x, 2) * cos(x));
}

double leftRect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i <= n - 1; i++) {
        sum += h * myFunction(a + i * h);
    }

    return sum;
}

double rightRect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 1; i <= n; i++) {
        sum += h * myFunction(a + i * h);
    }

    return sum;
}

double trap(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = myFunction(a) + myFunction(b);

    for (int i = 1; i <= n - 1; i++) {
        sum += 2 * myFunction(a + i * h);
    }

    sum *= h / 2;

    return sum;
}

double simpson(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = myFunction(a) + myFunction(b);
    int k;

    for (int i = 1; i <= n - 1; i++) {
        k = 2 + 2 * ( i % 2);
        sum += k * myFunction(a + i * h);
    }

    sum *= h / 3;

    return sum;
}

int main()
{
    int a = 1, b = 2;
    int n = 10;
    int start_time, end_time;

    start_time = clock();
    cout << "leftRect: " << leftRect(a, b, n) << endl;
    cout << "rightRect: " << rightRect(a, b, n) << endl;
    cout << "trapeeze: " << trap(a, b, n) << endl;
    cout << "simpson: " << simpson(a, b, n) << endl;
    end_time = clock() - start_time;

    cout << "time: " << (float)end_time / CLOCKS_PER_SEC << endl;
}