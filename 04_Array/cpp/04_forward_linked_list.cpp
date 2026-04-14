#include <iostream>
#include <forward_list>

// Helper function to print the list
void printList(const std::string& message, const std::forward_list<int>& lst) {
    std::cout << message << ": ";
    if (lst.empty()) {
        std::cout << "(empty)";
    } else {
        for (int val : lst) {
            std::cout << val << " ";
        }
    }
    std::cout << "\n";
}

int main() {
    std::cout << "--- std::forward_list Master Cheat Sheet ---\n\n";

    // 1. Initialization
    std::forward_list<int> flist = {30, 20, 50, 40, 40, 10};
    printList("Initial list", flist);

    // 2. Accessing the front element
    std::cout << "Front element: " << flist.front() << "\n\n";

    // 3. Adding Elements
    flist.push_front(99); // Add to the very beginning
    printList("After push_front(99)", flist);

    // Insert '25' right after the first element
    auto it = flist.begin(); 
    flist.insert_after(it, 25); 
    printList("After insert_after(begin(), 25)", flist);

    // Insert '0' at the very beginning using before_begin()
    flist.insert_after(flist.before_begin(), 0);
    printList("After insert_after(before_begin(), 0)", flist);
    std::cout << "\n";

    // 4. Removing Elements
    flist.pop_front(); // Removes the '0' we just added
    printList("After pop_front()", flist);

    // Erase the element right after the first one (removes '25')
    flist.erase_after(flist.begin());
    printList("After erase_after(begin())", flist);

    // Remove all instances of the number '40'
    flist.remove(40);
    printList("After remove(40)", flist);
    std::cout << "\n";

    // 5. Operations
    flist.sort(); // Sorts ascending: O(N log N)
    printList("After sort()", flist);

    // Let's add a duplicate '20' to test unique()
    flist.push_front(20);
    flist.sort();
    printList("Added duplicate and sorted", flist);
    
    flist.unique(); // Removes consecutive duplicates
    printList("After unique()", flist);

    flist.reverse(); // Reverses the entire list: O(N)
    printList("After reverse()", flist);

    // 6. Clearing the list
    flist.clear();
    printList("\nAfter clear()", flist);

    return 0;
}
