#include <iostream>
#include "averageScript/average.h"
#include <string>

using namespace std;

int main(){
    double grades[5] = {0};
    cout << "Input 5 numbers: ";
    for (int i = 0; i < 5; i++){
        cin >> grades[i];
    }
    cout << average(grades,sizeof(grades)/sizeof(grades[0])) << endl;
}