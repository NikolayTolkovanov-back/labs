#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
double Rech1(double x)
{
	return pow(x,3)+2*pow(x,2)+3*x+5;
}
double Rech2(double x)
{
	return 3*pow(x,2)+4*x+3;
}
int main()
{
	double x = -2, x0 = -2;
	double e = 0.000001;
	do
	{
		x0 = x;
		x = x0 - Rech1(x)/Rech2(x);
	}
	while (fabs(x0-x)>e);
	cout << setprecision (6)<<x;
	cin.get();
}