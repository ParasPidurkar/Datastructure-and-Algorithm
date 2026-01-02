/*
 * ======================================================================================
 * TOPIC: DYNAMIC ARRAYS IN KOTLIN (MutableList / ArrayList)
 * ======================================================================================
 * * FEATURES:
 * 1. Resizable: Can add/remove items freely.
 * 2. Backed by Array: Uses a resizing array under the hood.
 * 3. Two Types: 
 * - List (Read-only, fixed size view)
 * - MutableList (Read/Write, dynamic size) <- We use this here.
 */

fun main() {
    // 1. Creation
    // mutableListOf creates an ArrayList under the hood
    val numbers = mutableListOf(10, 20, 30) 

    // 2. Adding Elements
    numbers.add(40)      // Adds to the end
    numbers.add(0, 99)   // Adds 99 at index 0. List becomes [99, 10, 20, 30, 40]

    println("Current List: $numbers") // Kotlin prints lists nicely by default

    // 3. Accessing and Modifying
    val firstItem = numbers[0] // Get
    numbers[1] = 88            // Set (Change index 1 from 10 to 88)

    println("Modified List: $numbers")

    // 4. Removing Elements
    numbers.remove(40)     // Removes the specific element '40'
    numbers.removeAt(0)    // Removes the element at index 0

    println("After Removal: $numbers") // Size is now smaller

    // 5. Size
    println("Size: ${numbers.size}")

    // 6. Filtering (Functional Programming style)
    // Create a NEW list containing only numbers > 25
    val bigNumbers = numbers.filter { it > 25 }
    println("Filtered List (>25): $bigNumbers")
}
