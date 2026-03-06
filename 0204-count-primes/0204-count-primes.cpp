class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        int count = 0;

        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;

                for (int j = i * 2; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        return count;
    }
};

/*
========================
DRY RUN EXAMPLE
========================

Example Input:
n = 10

We need to count prime numbers LESS THAN 10.

----------------------------------------
Step 1: Initialization
----------------------------------------

isPrime array size = n + 1 = 11

Index:    0 1 2 3 4 5 6 7 8 9 10
isPrime:  T T T T T T T T T T T

count = 0

Note:
0 and 1 are not prime but the loop starts from 2,
so they are automatically ignored.

----------------------------------------
Iteration 1
----------------------------------------

i = 2

isPrime[2] = true
→ 2 is prime

count = 1

Mark multiples of 2:

j = 4  → isPrime[4] = false
j = 6  → isPrime[6] = false
j = 8  → isPrime[8] = false

Array becomes:

Index:    0 1 2 3 4 5 6 7 8 9
isPrime:  T T T T F T F T F T

----------------------------------------
Iteration 2
----------------------------------------

i = 3

isPrime[3] = true
→ 3 is prime

count = 2

Mark multiples of 3:

j = 6 → already false
j = 9 → isPrime[9] = false

Array becomes:

Index:    0 1 2 3 4 5 6 7 8 9
isPrime:  T T T T F T F T F F

----------------------------------------
Iteration 3
----------------------------------------

i = 4

isPrime[4] = false
→ Not prime

Skip

----------------------------------------
Iteration 4
----------------------------------------

i = 5

isPrime[5] = true
→ 5 is prime

count = 3

Multiples:

j = 10 → not < n
No marking occurs

----------------------------------------
Iteration 5
----------------------------------------

i = 6

isPrime[6] = false
Skip

----------------------------------------
Iteration 6
----------------------------------------

i = 7

isPrime[7] = true
→ 7 is prime

count = 4

Multiples:

j = 14 → exceeds n
No marking

----------------------------------------
Iteration 7
----------------------------------------

i = 8

isPrime[8] = false
Skip

----------------------------------------
Iteration 8
----------------------------------------

i = 9

isPrime[9] = false
Skip

----------------------------------------
Final Result
----------------------------------------

Prime numbers < 10:

2, 3, 5, 7

count = 4

Return 4

----------------------------------------
VISUAL SUMMARY
----------------------------------------

Initial:
2 3 4 5 6 7 8 9
T T T T T T T T

After removing multiples of 2:
2 3 4 5 6 7 8 9
T T F T F T F T

After removing multiples of 3:
2 3 4 5 6 7 8 9
T T F T F T F F

Remaining primes:
2 3 5 7

----------------------------------------

Time Complexity: O(n log log n)
Space Complexity: O(n)

*/