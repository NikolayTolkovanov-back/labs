#include <iostream>
#include <locale.h>
using namespace std;
int n, i, j, k, z;
int q, w, r, buf, bufx, bufb, t;
double d, s;

int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "Порядок: ";
    cin >> n;
    // Заполняем массивы
    double **a = new double *[n];
    double **a1 = new double *[n];
    for (i = 0; i <= n; i++)
        a[i] = new double[n];
    for (i = 0; i <= n; i++)
        a1[i] = new double[n];

    double *b = new double[n];
    double *x = new double[n];
    cout << "Введите коэфф. и свободные члены " << endl;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
            a1[i][j] = a[i][j];
        }
        cout << "b[" << i << "] = ";
        cin >> b[i];
    }
    // Проверка
    for (q = 1; q <= n; q++)
    {
        if (a[q][q] == 0)
        {
            for (w = 1; w <= n; w++)
            {
                if (a[w][q] != 0 && abs(a[w][q]) > abs(buf))
                    buf = a[w][q];
                else
                    continue;
            }
            for (r = 1; r <= n; r++)
            {
                if (a[r][q] == buf)
                {
                    for (t = 1; t <= n; t++)
                    {
                        bufx = a[r][t];
                        a[r][t] = a[q][t];
                        a[q][t] = bufx;
                    }
                    bufb = b[r];
                    b[r] = b[q];
                    b[q] = bufb;
                    buf = 0;
                    bufx = 0;
                    bufb = 0;
                }
                else
                    continue;
            }
        }
        else if (a[q][q] != 0)
            continue;
    }
    cout << "Проверка" << endl;
    for (int o = 1; o <= n; o++)
    {
        for (int p = 1; p <= n; p++)
        {
            cout << "a[" << o << "][" << p << "] = " << a[o][p] << endl;
        }
        cout << "b[" << o << "] = " << b[o] << endl;
    }

    // прямой ход
    for (k = 1; k <= n; k++) 
    {
        for (j = k + 1; j <= n; j++)
        {
            d = a[j][k] / a[k][k];
            for (i = k; i <= n; i++)
            {
                a[j][i] = a[j][i] - d * a[k][i];
            }
            b[j] = b[j] - d * b[k];
        }
    }

    // обратный ход
    for (k = n; k >= 1; k--)
    {
        d = 0;
        for (j = k + 1; j <= n; j++)
        {
            s = a[k][j] * x[j];
            d = d + s;
        }
        if (b[k] != 0)
            x[k] = (b[k] - d) / a[k][k];
        else
            x[k] = 0;
    }

    // Результат
    cout << "Корни системы: " << endl;
    for (i = n; i <= n && i >= 1; i--)
        cout << "x[" << i << "] = " << x[i] << endl;
    return 0;
}