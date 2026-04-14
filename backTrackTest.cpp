/**
 * 
 * @file backTrackTest.cpp
 * @author Rose Richards(rose.evelyn5550@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-04-14
 * 
 * @copyright Copyright (c) 2026
 * 
 */

 #include <iostream>
 using namespace std;


 int addTillFive(int initial){
    int sum = initial;
    cout << sum << endl;
    if (sum != 5){
        sum++;
        sum = addTillFive(sum);
    }
    return sum;
 }



 int main(){
    int start;

    cout << "Adding Until It Reaches 5 Test" << endl << "Starting Number: ";
    cin >> start;

    addTillFive(start);
    return 0;
 }