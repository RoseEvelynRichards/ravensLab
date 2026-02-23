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
    cout << "This should be equal to twelve: " << testNumB << endl;
    testNumA = 10;
    cout << "This should have updated: " << testNumA << endl;
    cout << "This should be the memory address of testNumA: " << &testNumA << endl
    << "And this should be the memory address of testNumB: " << &testNumB <<endl;
    //Both testNumA & testNumB should be equal to 10

    int* ptr = &testNumA; //should be equal to &testNumA
    cout << "This should be the memory address of testNumA without calling testNumA: " 
    << ptr << endl << "This should be the value of testNumaA without calling it: " << *ptr << endl;

    *ptr = 82;
    cout << "This should have been updated: " << *ptr << endl 
    << "This should be that number + 5: " << *ptr + 5 << endl;

    cout << "This should cout the size of testNumA: " << sizeof(testNumA) << endl
    << "This should cout the size of testNumH: " << sizeof(testNumB) << endl;

    //Alrighty here is the part that scares
    int* testNumC = new int;
    *testNumC = 35;
    cout << "This should cout testNumC: " << *testNumC << endl;
    delete testNumC;
    cout << "This shouldn't cout testNumC: " << *testNumC << endl;

    int* testNumD = new int[10];
    for (int i = 0; i < 10; i++){
        testNumD[i] = 35 + i;
    }

    for (int i = 0; i < 10; i++){
        cout << testNumD[i] << " ";
    }
    cout << endl;
    delete[] testNumD;


}