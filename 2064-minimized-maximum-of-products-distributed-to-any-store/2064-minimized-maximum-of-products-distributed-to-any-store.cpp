class Solution {
public:
    bool isPossible(int n, const vector<int>& quantities, int maxProductsPerStore) {
        long long requiredStores = 0;

        for (int quantity : quantities) {
            // ceil(quantity / maxProductsPerStore)
            requiredStores += (quantity + maxProductsPerStore - 1) / maxProductsPerStore;

            if (requiredStores > n) {
                return false;
            }
        }

        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isPossible(n, quantities, mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};

/*
==================== DRY RUN ====================

Input:
n = 7
quantities = [15, 10, 10]

Initial:
left = 1
right = 15
answer = 15

-------------------------------------------------
Iteration 1:
mid = 1 + (15 - 1) / 2
mid = 8

Check isPossible(8):

15 → ceil(15/8) = (15+7)/8 = 22/8 = 2
10 → ceil(10/8) = (10+7)/8 = 17/8 = 2
10 → ceil(10/8) = (10+7)/8 = 17/8 = 2

Total stores needed = 2 + 2 + 2 = 6
6 <= 7 → Possible

Update:
answer = 8
right = 7

-------------------------------------------------
Iteration 2:
left = 1, right = 7
mid = 1 + (7 - 1) / 2
mid = 4

Check isPossible(4):

15 → ceil(15/4) = (15+3)/4 = 18/4 = 4
10 → ceil(10/4) = (10+3)/4 = 13/4 = 3
10 → ceil(10/4) = 3

Total = 4 + 3 + 3 = 10
10 > 7 → Not possible

Update:
left = 5

-------------------------------------------------
Iteration 3:
left = 5, right = 7
mid = 5 + (7 - 5) / 2
mid = 6

Check isPossible(6):

15 → ceil(15/6) = (15+5)/6 = 20/6 = 3
10 → ceil(10/6) = (10+5)/6 = 15/6 = 2
10 → 2

Total = 3 + 2 + 2 = 7
7 <= 7 → Possible

Update:
answer = 6
right = 5

-------------------------------------------------
Iteration 4:
left = 5, right = 5
mid = 5

Check isPossible(5):

15 → ceil(15/5) = 3
10 → ceil(10/5) = 2
10 → 2

Total = 3 + 2 + 2 = 7
7 <= 7 → Possible

Update:
answer = 5
right = 4

-------------------------------------------------
Now:
left = 5, right = 4
Loop stops

Final Answer = 5

=================================================
*/