#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int count(int);

int main()
{
    srand(10);
    cout << rand() << endl;
    cout << rand() << endl;
}

int count(int x){
    x = x + 1;
    return x;
}