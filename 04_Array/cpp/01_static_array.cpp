/*
 * ======================================================================================
 * TOPIC: STATIC ARRAYS IN C++ (Detailed Walkthrough)
 * ======================================================================================
 *
 * WHAT IS A STATIC ARRAY?
 * 1. Fixed Size: The size must be known at "compile-time". It cannot change while the program runs.
 * 2. Contiguous Memory: Elements are stored next to each other in RAM.
 * 3. Stack Allocation: Usually allocated on the "Stack" (fast memory), not the "Heap".
 *
 * This tutorial covers:
 * A. C-Style Raw Arrays (The traditional way)
 * B. Multidimensional Arrays (Matrices)
 * C. Array Decay (Passing arrays to functions)
 * D. The `static` keyword (Lifetime extension)
 * E. std::array (The Modern C++ Standard)
 * ======================================================================================
 */

#include <iostream>
#include <array>    // Required for Section E (std::array)
#include <algorithm> // Required for sorting/searching

// ======================================================================================
// SECTION C: FUNCTIONS AND ARRAY DECAY
// ======================================================================================

/*
 * When you pass a raw array to a function, it "Decays" into a pointer.
 * The function receives the memory address of the first element, NOT the full array.
 *
 * Implication: `sizeof(arr)` inside the function will return the size of a pointer (usually 8 bytes),
 * not the size of the array data. This is why we MUST pass the size separately.
 */
void printRawArray(int arr[], int size) {
    // Note: 'arr' here is actually an int* (pointer)
    std::cout << "Function Output: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    // Use std::cout for printing
    using namespace std;

    cout << "=== SECTION A: DECLARATION AND INITIALIZATION ===\n";

    /*
     * 1. Declaration
     * Syntax: DataType Name[ConstantSize];
     *
     * WARNING: If declared inside a function without initialization,
     * the slots contain "Garbage Values" (random data left in memory).
     */
    int garbageArray[5]; 
    // garbageArray now holds random numbers like -858993460...

    /*
     * 2. Initialization List
     * We can define values immediately.
     */
    int luckyNumbers[5] = {10, 20, 30, 40, 50};

    /*
     * 3. Partial Initialization
     * If we provide fewer values than the size, the rest become 0.
     */
    int partialArray[5] = {1, 2}; // Becomes {1, 2, 0, 0, 0}

    /*
     * 4. Implicit Sizing
     * If we omit the number inside [], the compiler counts the elements for us.
     */
    int autoSized[] = {100, 200, 300}; // Compiler knows size is 3

    // Printing to prove partial initialization
    cout << "Partial Array index 0: " << partialArray[0] << endl; // 1
    cout << "Partial Array index 4: " << partialArray[4] << endl; // 0

    cout << "\n=== SECTION B: MEMORY AND ACCESS ===\n";

    /*
     * HOW ACCESS WORKS:
     * Arrays are 0-indexed.
     * Address Calculation: StartAddress + (Index * SizeOfDataType).
     *
     * Example Memory (assuming int is 4 bytes):
     * Index:     0       1       2
     * Value:    [10]    [20]    [30]
     * Address:  0x100   0x104   0x108
     */

    // Modifying an element
    luckyNumbers[2] = 999; // Changing 30 to 999

    cout << "Element at index 2 is now: " << luckyNumbers[2] << endl;

    /*
     * SAFETY WARNING: BUFFER OVERFLOW
     * C++ does NOT check bounds for raw arrays.
     * Accessing luckyNumbers[10] might crash your program or read secret memory.
     * Always ensure index < size.
     */

    cout << "\n=== SECTION C: LOOPING AND SIZE ===\n";

    /*
     * Calculating Size of Raw Arrays:
     * sizeof(array) returns total bytes.
     * sizeof(array[0]) returns bytes of one element.
     */
    int totalBytes = sizeof(luckyNumbers);
    int elementBytes = sizeof(luckyNumbers[0]);
    int arrayLength = totalBytes / elementBytes;

    cout << "Total Bytes: " << totalBytes << " | Element Bytes: " << elementBytes << endl;
    cout << "Calculated Length: " << arrayLength << endl;

    // 1. Traditional For Loop
    cout << "Loop 1: ";
    for (int i = 0; i < arrayLength; i++) {
        cout << luckyNumbers[i] << " ";
    }
    cout << endl;

    // 2. Range-Based For Loop (C++11 and later)
    // This reads: "For every number 'n' inside 'luckyNumbers'..."
    // This is safer and cleaner.
    cout << "Loop 2: ";
    for (int n : luckyNumbers) {
        cout << n << " ";
    }
    cout << endl;

    // Call the function we defined at the top
    printRawArray(luckyNumbers, 5);


    cout << "\n=== SECTION D: MULTIDIMENSIONAL ARRAYS ===\n";

    /*
     * Think of this as a grid or matrix.
     * Syntax: Type Name[Rows][Columns];
     * Memory is still contiguous (Row 1 follows Row 0 directly).
     */
    int matrix[2][3] = {
        {1, 2, 3}, // Row 0
        {4, 5, 6}  // Row 1
    };

    // Accessing Row 1, Column 2 (Value 6)
    cout << "Matrix[1][2] = " << matrix[1][2] << endl;

    // Looping a matrix requires nested loops
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++) {
            cout << "[" << matrix[row][col] << "]";
        }
        cout << endl;
    }


    cout << "\n=== SECTION E: std::array (MODERN C++) ===\n";

    /*
     * Raw arrays (int arr[5]) have issues:
     * 1. They decay to pointers (losing size info).
     * 2. They don't have built-in methods like .size() or .sort().
     *
     * SOLUTION: std::array (Included in <array>)
     * It effectively wraps a raw array but makes it an object.
     * It has zero performance cost compared to raw arrays.
     */

    // Syntax: std::array<Type, Size> Name;
    std::array<int, 4> modernArray = {10, 20, 30, 40};

    // Benefit 1: We know the size effortlessly
    cout << "Modern Array Size: " << modernArray.size() << endl;

    // Benefit 2: Bounds checking (Optional)
    // modernArray[10] would still be unsafe, BUT:
    try {
        // .at() throws an error if we go out of bounds, preventing corruption
        modernArray.at(10) = 5; 
    } catch (const out_of_range& e) {
        cout << "Error caught: " << e.what() << endl;
    }

    // Benefit 3: Assignment
    std::array<int, 4> copyArray;
    copyArray = modernArray; // You CANNOT do this with raw arrays (int a[] = b[])!
    
    cout << "Copied array index 0: " << copyArray[0] << endl;


    cout << "\n=== SECTION F: THE 'STATIC' KEYWORD ===\n";

    /*
     * Often, "Static Array" implies Fixed-Size.
     * However, the C++ keyword `static` changes the LIFETIME of the variable.
     */
    {
        // A normal local array is created when this block starts
        // and DESTROYED when this block ends (} bracket).
        int localArray[3] = {1, 1, 1};

        // A `static` array is created ONLY ONCE when the program starts.
        // It stays in memory even after this block ends.
        // If we re-enter this block, it remembers the old values.
        static int permanentArray[3] = {1, 1, 1};
        
        cout << "Static Keyword logic executed (Internal)." << endl;
    }

    return 0;
}
