#include <iostream>
#include <chrono>
#include <vector>
#include <cmath> // For an actual calculation

int main()
{
    // Define the number of operations
    const long long iterations = 1000000000; // One billion iterations

    // Start the high-resolution timer
    auto start = std::chrono::high_resolution_clock::now();

    // Perform a computationally intensive task to prevent compiler optimization
    // We use a volatile variable or a calculation that has a visible side effect
    double result = 0.0;
    for (long long i = 0; i < iterations; ++i)
    {
        // Simple calculation to keep the CPU busy
        result += std::sin(i * 0.000001); // Use sin as an example of a calculation
    }

    // Stop the timer
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> duration = end - start;

    // Print the result (use the 'result' variable to ensure it's not optimized away)
    std::cout << "Test completed." << std::endl;
    std::cout << "Result (to prevent optimization): " << result << std::endl;
    std::cout << "Execution time for " << iterations << " operations: "
              << duration.count() << " seconds" << std::endl;

    return 0;
}