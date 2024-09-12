#include <iostream>
using namespace std;

int josephus(int n, int k) {
    if (n == 1)
        return 0;
    else
        return (josephus(n - 1, k) + k) % n;
}

int main() {
    int n, k;
    cout << "Enter number of people (n): ";
    cin >> n;
    cout << "Enter step size (k): ";
    cin >> k;

    int survivor = josephus(n, k);
    cout << "The last person at index: " << survivor << endl;

    return 0;
}
