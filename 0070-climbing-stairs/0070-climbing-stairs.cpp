class Solution {
public:
    int climbStairs(int n) {

        // Step 1: Base case
        // If there are 0 or 1 steps, there is exactly 1 way to climb
        // n = 0 → do nothing
        // n = 1 → take one step
        if (n <= 1) {
            return n;
        }

        // Step 2: Create a DP array
        // arr[i] will store the number of ways to reach step i
        // Size is n+1 to include index 0 to n
        int arr[n + 1];

        // Step 3: Initialize base cases
        // arr[0] = 1 → one way to stay at ground (do nothing)
        // arr[1] = 1 → one way to reach step 1
        arr[0] = 1;
        arr[1] = 1;

        // Step 4: Fill the DP array
        for (int i = 2; i <= n; i++) {

            // Number of ways to reach step i
            // = ways from step (i-1) + ways from step (i-2)
            arr[i] = arr[i - 1] + arr[i - 2];
        }

        // Step 5: Return number of ways to reach step n
        return arr[n];
    }
};
