class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        const int INF = INT_MAX / 2;

        // Store only the previous 3 DP states and current state
        vector<int> dp(4, INF);

        // Starting at step 0 costs nothing
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {

            // Reset the current DP slot
            dp[i % 4] = INF;

            // We can reach step i from the previous 3 steps
            for (int j = max(0, i - 3); j < i; j++) {

                int jump = i - j;

                int currentCost = dp[j % 4]
                                + costs[i - 1]
                                + jump * jump;

                dp[i % 4] = min(dp[i % 4], currentCost);
            }
        }

        return dp[n % 4];
    }
};

/*
APPROACH:
1. Use Dynamic Programming to calculate the minimum cost
   required to reach each step.

2. Define:
      dp[i] = Minimum cost required to reach step i.

3. BASE CASE:
      dp[0] = 0

   We start at step 0 without paying anything.

4. TRANSITIONS:
   We can reach step i from:
      - Step i - 1 (jump of 1)
      - Step i - 2 (jump of 2)
      - Step i - 3 (jump of 3)

5. Calculate the cost of each possible jump:
      Previous DP cost + Landing cost + Jump distance squared.

   Formula:
      dp[i] = min(
          dp[i-1] + costs[i-1] + 1,
          dp[i-2] + costs[i-1] + 4,
          dp[i-3] + costs[i-1] + 9
      )

   Only valid previous steps are considered.

6. SPACE OPTIMIZATION:
   Since each state depends only on the previous
   three states, we use a circular DP array of size 4.

   dp[i % 4] stores the current state.
   dp[(i-1) % 4], dp[(i-2) % 4], and dp[(i-3) % 4]
   store the previous three states.

7. Return dp[n % 4] as the minimum cost to reach
   the final step.

DRY RUN:
Input:
n = 4
costs = [1, 2, 3, 4]

Step 0:
   dp[0] = 0

Step 1:
   From step 0:
   0 + 1 + (1-0)^2 = 2

   dp[1] = 2

Step 2:
   From step 0:
   0 + 2 + 4 = 6

   From step 1:
   2 + 2 + 1 = 5

   dp[2] = 5

Step 3:
   From step 0:
   0 + 3 + 9 = 12

   From step 1:
   2 + 3 + 4 = 9

   From step 2:
   5 + 3 + 1 = 9

   dp[3] = 9

Step 4:
   From step 1:
   2 + 4 + 9 = 15

   From step 2:
   5 + 4 + 4 = 13

   From step 3:
   9 + 4 + 1 = 14

   dp[4] = 13

Output:
   13

OPTIMAL PATH:
   0 → 1 → 2 → 4

Total cost:
   2 + 3 + 8 = 13

COMPLEXITY:
Time Complexity:
   O(n)
   Each step considers at most 3 previous states.
   Therefore, total operations are proportional to n.

Space Complexity:
   O(1)
   Only 4 DP positions are maintained in the circular array.

PATTERN:
Dynamic Programming + Space Optimization
Fixed-size State Transition (Previous 3 States)
*/