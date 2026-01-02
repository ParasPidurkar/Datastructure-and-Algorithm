/*
 * ======================================================================================
 * TOPIC: ARRAYS IN KOTLIN (Detailed Walkthrough)
 * ======================================================================================
 *
 * WHAT IS AN ARRAY IN KOTLIN?
 * 1. Fixed Size: Just like C++, the size is set at creation and cannot change.
 * 2. Objects vs Primitives: Kotlin has `Array<T>` (Boxed) and `IntArray`, `ByteArray`, etc. (Primitive/Optimized).
 * 3. Safe: Unlike C++, Kotlin arrays know their own size and check bounds (preventing memory leaks).
 * 4. Initialization: Kotlin ALWAYS initializes arrays (usually to 0 or null). No "Garbage Values".
 *
 * This tutorial covers:
 * A. Creating Arrays (Constructors vs Helper functions)
 * B. Access and Modification
 * C. Functions (No "Decay" issue like C++)
 * D. Multidimensional Arrays (Arrays of Arrays)
 * E. Generic Arrays vs Primitive Arrays (Performance)
 * ======================================================================================
 */

// ======================================================================================
// SECTION C PRE-DEFINITION: FUNCTIONS AND PASSING ARRAYS
// ======================================================================================

/*
 * Unlike C++, Kotlin arrays are OBJECTS.
 * When passed to a function, they do NOT "decay" into pointers.
 * They retain their metadata, including their size.
 */
fun printArray(arr: IntArray) {
    print("Function Output: ")
    // We don't need to pass 'size' separately! The array knows it.
    for (element in arr) {
        print("$element ")
    }
    println()
    println("Inside function, size is still known: ${arr.size}")
}

fun main() {
    println("=== SECTION A: DECLARATION AND INITIALIZATION ===")

    /*
     * 1. Declaration with Default Values
     * In C++, `int arr[5];` might contain garbage.
     * In Kotlin, `IntArray(5)` guarantees all elements are 0.
     */
    val zeroArray = IntArray(5) // [0, 0, 0, 0, 0]
    println("Default Init (Index 0): ${zeroArray[0]}")

    /*
     * 2. Initialization with Values (Helper Function)
     * The compiler infers the size (5) and types automatically.
     */
    val luckyNumbers = intArrayOf(10, 20, 30, 40, 50)

    /*
     * 3. Constructor with Lambda (Dynamic Logic)
     * This creates an array of size 5, where each element is index * 2.
     * C++ requires a loop to do this; Kotlin does it in one line.
     */
    val logicArray = IntArray(5) { index -> index * 2 } // [0, 2, 4, 6, 8]
    println("Logic Init (Index 3): ${logicArray[3]}") // Prints 6


    println("\n=== SECTION B: MEMORY AND ACCESS ===")

    /*
     * Access works exactly like C++ using brackets [].
     * However, in Kotlin, arrays are 0-indexed objects on the Heap.
     */

    // Modifying an element
    luckyNumbers[2] = 999
    println("Element at index 2 is now: ${luckyNumbers[2]}")

    /*
     * SAFETY WARNING: BOUNDS CHECKING
     * C++ allows you to access luckyNumbers[10] and crash/read private memory.
     * Kotlin throws an explicit Exception immediately.
     */
    try {
        // This will throw ArrayIndexOutOfBoundsException
        val crash = luckyNumbers[10]
    } catch (e: ArrayIndexOutOfBoundsException) {
        println("Error caught: Kotlin prevented a buffer overflow! ${e.message}")
    }


    println("\n=== SECTION C: LOOPING AND SIZE ===")

    /*
     * 1. The 'size' property
     * No need for `sizeof(arr) / sizeof(arr[0])` math.
     */
    println("Array Size: ${luckyNumbers.size}")

    // 2. Standard For-Each Loop (Cleanest)
    print("For-Each Loop: ")
    for (num in luckyNumbers) {
        print("$num ")
    }
    println()

    // 3. Loop with Index (Best of both worlds)
    print("Index Loop: ")
    for ((index, value) in luckyNumbers.withIndex()) {
        // We have both the position and the data
        if (index == 0) print("First is $value... ")
    }
    println()

    // Pass to function (Proof that size info is preserved)
    printArray(luckyNumbers)


    println("\n=== SECTION D: MULTIDIMENSIONAL ARRAYS ===")

    /*
     * Kotlin does not have continuous memory blocks for matrices like C++ `int matrix[2][3]`.
     * Instead, we use "Arrays of Arrays".
     *
     * Structure:
     * [ Array Ref ] -> [ 1, 2, 3 ]
     * [ Array Ref ] -> [ 4, 5, 6 ]
     */

    val matrix = arrayOf(
        intArrayOf(1, 2, 3), // Row 0
        intArrayOf(4, 5, 6)  // Row 1
    )

    // Accessing Row 1, Column 2
    println("Matrix[1][2] = ${matrix[1][2]}") // Prints 6

    // Nested Looping
    for (row in matrix) {
        // 'row' is an IntArray
        print("[ ")
        for (col in row) {
            print("$col ")
        }
        print("] ")
    }
    println()


    println("\n=== SECTION E: GENERIC VS PRIMITIVE (The 'Boxed' Trap) ===")

    /*
     * In C++, `std::vector<int>` or `int[]` are efficient.
     * In Kotlin/Java, we have a distinction:
     *
     * 1. IntArray (Primitive)
     * - Stores raw `int` values (4 bytes).
     * - Fast, low memory.
     * - Equivalent to C++ `int[]`.
     *
     * 2. Array<Int> (Boxed)
     * - Stores `Integer` OBJECTS.
     * - Each number has wrapper overhead.
     * - References are stored, not values directly.
     */

    // Primitive (Efficient)
    val primitiveArr: IntArray = intArrayOf(1, 2, 3)

    // Boxed (Heavy - Avoid for math/performance)
    val objectArr: Array<Int> = arrayOf(1, 2, 3)

    println("Primitive arrays are preferred for performance in Kotlin.")


    println("\n=== SECTION F: THE 'STATIC' KEYWORD (Lifetime) ===")

    /*
     * Kotlin does not have "function-local static variables" like C++.
     * (e.g., `static int x = 0;` inside a function).
     *
     * To achieve the same effect (variables that persist across function calls),
     * we typically use a "Companion Object" or a closure.
     */

    // Calling the simulator function multiple times
    countExecutions()
    countExecutions()
    countExecutions()
}

/*
 * Simulating C++ `static` variable behavior.
 * Since we can't put `static` inside a function, we put the variable
 * in a Singleton object outside the function.
 */
object StaticMemory {
    var count = 0 // This lives for the entire program duration
}

fun countExecutions() {
    StaticMemory.count++
    println("Function called ${StaticMemory.count} times (Persisted memory)")
}
