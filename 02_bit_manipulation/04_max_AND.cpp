#include <iostream>
#include <vector>
using namespace std;

int maxAndPair(vector<int>& arr) {
    int result = 0;
    int count;
    int n = arr.size();
    
    for (int bit = 31; bit >= 0; --bit) {
        // Assume setting this bit in the result
        int tempResult = result | (1 << bit);
        count = 0;
        
        // Count how many elements would have this bit set
        for (int num : arr) {
            if ((num & tempResult) == tempResult) {
                count++;
            }
        }
        
        // If at least two elements satisfy, update the result
        if (count >= 2) {
            result = tempResult;
        }
    }
    
    return result;
}

int main() {
    vector<int> arr = {4, 8, 12, 16};
    cout << "Maximum AND value: " << maxAndPair(arr) << endl;
    return 0;
}
