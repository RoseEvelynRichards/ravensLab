/**
 * @file main.cpp
 * @author Rose Richards (rose.evelyn5550@gmail.com)
 * @brief Learning how to use pointers
 * @version 0.1
 * @date 2026-02-23
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <string>
#include <iostream>
using namespace std;
//Trying to learn to understand pointers

int main(){
    int testNumA = 12;
    int &testNumB = testNumA;
    cout << "This should be equal to what was 12: " << testNumB << endl;
    testNumA = 10;
    cout << "This should have updated: " << testNumA << endl;
    cout << "This should be the memory address of testNumA: " << &testNumA << endl
    << "And this should be the memory address of testNumB: " << &testNumB <<endl;
}