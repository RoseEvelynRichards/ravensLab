/**
 * @file richards_score_analyzer.cpp
 * @author Rose Richards (rricha58@skyhawks.utm.edu)
 * @brief A console program that reads a collection of integer student scores from 0 through 100
 * @version 0.1
 * @date 2026-09-26
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
//just fyi I dont tend to use namespace std just cause I was taught not to


//finds and returns minimum score
int minScore(int scores[], int size){
    int minimumScore = 101;
    for (int i = 0; i < size; i++){
        if (scores[i] < minimumScore) minimumScore = scores[i];
    }
    return minimumScore;
}

//finds and returns max score
int maxScore(int scores[], int size){
    int maximumScore = -1;
    for (int i = 0; i < size; i++){
        if (scores[i] > maximumScore) maximumScore = scores[i];
    }
    return maximumScore;
}

//finds and returns the average score
double averageScore(int scores[], int size){
    double avg = 0;
    for (int i = 0; i < size; i++){
        avg = avg + scores[i];
    }
    avg = avg / size;
    return avg;
}

//finds and returns the amount of scores above average
int higherThanAvg(int scores[], int size){
    double avg = averageScore(scores, size);
    int amount = 0;
    for (int i = 0; i < size; i++){
        if (scores[i] > avg) amount++;
    }
    return amount;
}

int main(){
    int scoreTotal;
    int *scores;

    std::cout << "How many scores will be entered?: ";
    std::cin >> scoreTotal;
    while (scoreTotal < 1){
        std::cout << "There cannot be less than one input. \nPlease choose a new value: ";
        std::cin >> scoreTotal;
    }
    std::cout << std::endl;

    //start of part A
    //allocating memory, set up a failure response
    scores = new int[scoreTotal];
    if (scores == nullptr){
        delete scores;
        std::cout << "Memory allocation failure, rerun program";
        return 0;
    }

    //dynamic array allocation
    for (int i = 0; i < scoreTotal; i++){
        std::cout << "Insert score between 0 and 100: ";
        std::cin >> scores[i];
        if ( (scores[i] < 0) or (scores[i] > 100)){
            std::cout << "Score must be between 0 and 100: ";
            std::cin >> scores[i];
        }
    }

    //this looks horrific and is stressing me out but whateverrrr
    std::cout << std::endl << "Lowest Score: " << minScore(scores,scoreTotal) <<std::endl
    << "Highest Score: " << maxScore(scores,scoreTotal) << std::endl
    << "Average Score: " << averageScore(scores,scoreTotal) << std::endl
    << "Amount of Scores Above Average: " << higherThanAvg(scores,scoreTotal) << std::endl;

    std::cout << "Pointer Arithmetic Numbers: ";
    for (int i = 0; i < scoreTotal; i++){
        std::cout << *(scores + i) << " ";
    }

    //start of part B
    //moving the array to a vector
    std::vector<int> scoresVec;
    for (int i = 0; i < scoreTotal; i++) scoresVec.push_back(scores[i]);

    delete scores;
    scores = nullptr;
    std::cout << std::endl;
    //end of part A

    //displays the whole vector with iterator
    std::cout << "Vector Display: ";
    for (std::vector<int>::iterator it = scoresVec.begin(); it != scoresVec.end(); ++it) std::cout << *it << " ";

    //search for number's presence
    int target;
    std::cout << std::endl << "Target Number: ";
    std::cin >> target;

    //searches for a number
    auto it = std::find(scoresVec.begin(), scoresVec.end(), target);
    if (it != scoresVec.end()) std::cout << "Target Present" <<std::endl;
    else std::cout << "Target Not Present" <<std::endl ;

    //sorts and prints
    std::sort(scoresVec.begin(), scoresVec.end());
    for (int i : scoresVec) std::cout << i << " ";
    std::cout << std::endl;

    //prints minimum and maximum using vector
    std::cout << "Minimum Value Through min_element: "<< *std::min_element(scoresVec.begin(), scoresVec.end()) <<std::endl;
    std::cout << "Maximum Value Through max_element: "<< *std::max_element(scoresVec.begin(), scoresVec.end()) <<std::endl;

    std::cout << "Vector Size: " << scoresVec.size() << std::endl << "Vector Capacity: " << scoresVec.capacity();

    std::cout << std::endl;
    return 0;
 }