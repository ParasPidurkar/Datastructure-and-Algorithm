/*
 * ======================================================================================
 * TOPIC: DYNAMIC ARRAYS IN C++ (std::vector)
 * ======================================================================================
 * * FEATURES:
 * 1. Resizable: Grows automatically when you add elements.
 * 2. Contiguous Memory: Like arrays, elements are stored side-by-side (fast access).
 * 3. Automatic Memory Management: No need for 'new' or 'delete'.
 */

#include <iostream>
#include <vector>
#include <algorithm> // For sorting

using namespace std;

int main() {
    // 1. Creation
    // Syntax: vector<DataType> name;
    vector<int> numbers; 

    // 2. Adding Elements (push_back)
    // The vector automatically resizes to fit these.
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    cout << "Initial Size: " << numbers.size() << endl; // Output: 3

    // 3. Accessing Elements
    // Use [] like a normal array, or .at() for safety
    cout << "First element: " << numbers[0] << endl;
    cout << "Second element: " << numbers.at(1) << endl;

    // 4. Removing Elements
    numbers.pop_back(); // Removes the last element (30)
    cout << "Size after pop: " << numbers.size() << endl; // Output: 2

    // 5. Inserting at a specific position
    // Insert '99' at the beginning (index 0)
    numbers.insert(numbers.begin(), 99); 
    // State: [99, 10, 20]

    // 6. Looping
    cout << "Current Vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // 7. Dynamic Resizing logic (Capacity vs Size)
    // Size: How many elements are currently in use.
    // Capacity: How much memory is actually allocated (usually more than size to prevent frequent reallocations).
    cout << "Capacity: " << numbers.capacity() << endl;

    return 0;
}
