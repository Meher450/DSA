class Solution {
public:
    int tribonacci(int n) {

        // Step 1: Handle base cases
        // According to definition:
        // T0 = 0
        // T1 = 1
        // T2 = 1
        if (n <= 2) {
            if (n == 0) {
                return 0;
            }
            return 1;
        }

        // Step 2: Create a DP array
        // arr[i] will store the value of T(i)
        int arr[n + 1];

        // Step 3: Initialize base Tribonacci values
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;

        // Step 4: Fill the DP array from 3 to n
        // Each value depends on the previous three values
        for (int i = 3; i <= n; i++) {

            // T(i) = T(i-1) + T(i-2) + T(i-3)
            arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
        }

        // Step 5: Return the nth Tribonacci number
        return arr[n];
    }
};
