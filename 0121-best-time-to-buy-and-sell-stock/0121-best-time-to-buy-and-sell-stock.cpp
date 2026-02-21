class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // If there are less than 2 prices, no transaction can be made
        if (prices.size() <= 1) return 0;

        // Minimum price seen so far (best buying price)
        int buy = prices[0];

        // Maximum profit found so far
        int profit = 0;

        // Traverse prices starting from day 1
        for (int i = 1; i < prices.size(); i++) {

            // If current price is lower than the minimum seen so far,
            // update the buying price
            if (prices[i] < buy) {
                buy = prices[i];
            } 
            // Otherwise, check if selling today yields better profit
            else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }
        }

        // Return the maximum profit possible
        return profit;
    }
};


/*
========================
DRY RUN (After Execution)
========================

Example Input:
prices = [7, 1, 5, 3, 6, 4]

Step 1:
buy = 7
profit = 0

i = 1, price = 1
1 < 7 → update buy = 1
profit = 0

i = 2, price = 5
5 - 1 = 4 > 0 → update profit = 4

i = 3, price = 3
3 - 1 = 2 (not > 4)
No change

i = 4, price = 6
6 - 1 = 5 > 4 → update profit = 5

i = 5, price = 4
4 - 1 = 3 (not > 5)
No change

Final Result:
profit = 5

Best transaction:
Buy at 1
Sell at 6


---------------------------------

Example 2:
prices = [7, 6, 4, 3, 1]

buy keeps updating to smaller values:
7 → 6 → 4 → 3 → 1

No day gives positive profit.

Final profit = 0
*/