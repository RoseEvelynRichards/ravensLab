#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void bubbleSort(std::vector<int>& v) {
    int n = v.size();

    // Outer loop that corresponds to the number of
    // elements to be sorted
    for (int i = 0; i < n - 1; i++) {

        // Last i elements are already
        // in place
        for (int j = 0; j < n - i - 1; j++) {
          
          	// Comparing adjacent elements
            if (v[j] > v[j + 1])
              
              	// Swapping if in the wrong order
                std::swap(v[j], v[j + 1]);
        }
    }
}

bool isPresent(const std::vector<int>& v, int val){
    return std::binary_search(v.begin(), v.end(), val);
}



int main(){
    std::vector<int>values = {14,5,9,2,11,7};
    std::cout << "Unsorted: ";
    for (auto i: values){
        std::cout << i << " ";
    }

    std::cout  << "\nSorted: ";
    bubbleSort(values);
    for (auto i: values){
        std::cout << i << " ";
    }

    std::cout << "\nSearching for 11: ";
    std::string result = (isPresent(values, 11)) ? "Found" : "Not Found";
    std::cout << "Results: " << result << "\n";

    std::cout << "Searching for 18: ";
    result = (isPresent(values, 18)) ? "Found" : "Not Found";
    std::cout << "Results: " << result;

    std::cout << std::endl;
    return 0;
}