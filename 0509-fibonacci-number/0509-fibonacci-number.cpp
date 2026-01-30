class Solution {
public:
    int fib(int n) {

        // Step 1: Base case handling
        // If n is 0 or 1, the Fibonacci number is n itself
        if (n <= 1) {
            return n;
        }

        // Step 2: Create a DP array to store Fibonacci values
        // arr[i] will store the value of fib(i)
        // Size is n+1 because we need values from index 0 to n
        int arr[n + 1];

        // Step 3: Initialize base Fibonacci values
        // According to definition:
        // fib(0) = 0, fib(1) = 1
        arr[0] = 0;
        arr[1] = 1;

        // Step 4: Fill the DP array from index 2 to n
        // Each Fibonacci number is the sum of the previous two
        for (int i = 2; i <= n; i++) {

            // fib(i) = fib(i-1) + fib(i-2)
            arr[i] = arr[i - 1] + arr[i - 2];
        }

        // Step 5: The nth Fibonacci number is stored at arr[n]
        return arr[n];
    }
};
