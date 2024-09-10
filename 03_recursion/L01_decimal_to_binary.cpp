#include <iostream>
using namespace std;

// Recursive function to convert decimal to binary
void decimalToBinary(int n) {
    // Base case: when n becomes 0
    if (n == 0)
        return;

    // Recursive case: call the function with n/2
    decimalToBinary(n / 2);

    // After recursion, print the remainder
    cout << (n % 2);
}

int main() {
    int num;
    cout << "Enter a decimal number: ";
    cin >> num;

    if (num == 0) {
        cout << "0";
    } else {
        cout << "Binary representation of " << num << " is: ";
        decimalToBinary(num);
    }

    cout << endl;
    return 0;
}
