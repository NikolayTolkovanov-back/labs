#include <iostream>
 
using namespace std;
 
double lagranz(double x, int n, double x_arr[], double y_arr[]){
 
    double sum = 0;
    for (int i = 0; i < n; i++){
 
        double l = 1;
        for (int j = 0; j < n; j++)
            if (j != i){
                l = l* (x - x_arr[j]) / (x_arr[i] - x_arr[j]);
 
            }
 
        sum += y_arr[i] * l;
    }
    return sum;
}

double Newton(double x, int n, double x_arr[], double y_arr[]){
    
    double sum = y_arr[0];
    for(int i = 1; i < n; ++i){
        
        double F = 0;
        for(int j = 0; j <= i; ++j){
            
            double den = 1;
            for(int k = 0; k <= i; ++k)
                if (k != j) 
                    den *= (x_arr[j] - x_arr[k]);

            F += y_arr[j]/den;
        }
        
        
        for(int k = 0; k < i; ++k)
            F *= (x - x_arr[k]);
        sum += F;
    }
    return sum;
}

int main()
{   
    double step;
    cout<<"step: ";
    cin>>step;
    int n = 5;
    double x_arr[5] = {2.119, 3.618, 5.342, 7.859, 8.934};
    double y_arr[5] = {0.605, 0.718, 0.105, 2.157, 3.431};
    cout<<"lagranz:"<<endl;
    for (double x = x_arr[0]; x < x_arr[4]; x += step){
        cout << "f(" << x << ") = " <<lagranz(x, n, x_arr, y_arr) << endl;
    }
    cout<<"Newton:"<<endl;
    for (double x = x_arr[0]; x < x_arr[4]; x += step){
        cout << "f(" << x << ") = " <<Newton(x, n, x_arr, y_arr) << endl;
    }
    return 0;
}
 
