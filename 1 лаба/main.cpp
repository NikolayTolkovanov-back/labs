#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;
//Функция для полинома:
double myFunction(double x)
{
    // return sin(x);
    return 4 * (1 + pow(x, 0.5)) * log(x) - 1;
}

//Функция поиска корня:
double findRoot(double (*f)(double), double a, double b, double eps)
{

    double x;
    int steps = 0;

    while ((b - a) / 2 > eps)
    {
        steps++;
        x = (a + b) / 2;
        if ((f(a) * f(x)) > 0)
            a = x;
        else
            b = x;
    }

    cout << "x: " << x << endl;
    cout << "f(x): " << f(x) << endl;
    cout << "eps: " << eps << endl;
    cout << "steps: " << steps << endl;
    steps = 0;
    return x;
}

double teoreticSteps(double a, double b, double eps) {
    double k = (log(b - a) - log(eps)) / log(2) + 1;
    return floor(k);
}

int main()
{
    //Интервал, погрешность и корень:
    double a, b, eps = 0.01;
    double x_array[100], y_array[100], intervals;
    double counter = 0.1;
    int start_time, end_time;
    // Заполняем массивы:
    for (int i = 0; i < 100; i++) {
        x_array[i] = counter;
        y_array[i] = myFunction(counter);
        // cout << "i: " << i <<
        // " x: " << x_array[i] <<
        // " y: " << y_array[i] << endl;
        counter += 0.1;
    }
    // Ищем корни в интервалах:
    for (int j = 1; j < sizeof(y_array) / sizeof(y_array[0]); j++) {
        if (y_array[j - 1] * y_array[j] < 0) {
            a = x_array[j - 1];
            b = x_array[j];

            start_time = clock();
            findRoot(myFunction, a, b, eps);
            end_time = clock() - start_time;
            
            cout << "time: " << (float)end_time / CLOCKS_PER_SEC << endl;
            cout << "teoretic steps: " << teoreticSteps(a, b, eps) << "\n\n" << endl;
        }
    }

    // system("python main.py");
}