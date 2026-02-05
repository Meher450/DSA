class Solution {
public:
    int atMostDistinct(vector<int> &arr,int k){
        int n=arr.size(), si=0, ei=0, count=0, subArrayCount=0;
        vector<int>freq(n+1,0);

        while(ei<n){
            if(freq[arr[ei++]]++ == 0) count++;
            while(count > k){
                if(freq[arr[si++]]-- == 1) count--;
            }
            subArrayCount += ei-si;
        }
        return subArrayCount;
    }
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        return atMostDistinct(arr,k) - atMostDistinct(arr,k-1);
    }
};
/*
Input for Dry Run
arr = [1, 2, 1, 2, 3]
k = 2


Expected answer:

7

STEP 1: High-level strategy

We compute:

exactly K distinct
= atMost(K) − atMost(K − 1)


So we run:

atMostDistinct(arr, 2)

atMostDistinct(arr, 1)

Subtract

STEP 2: Understanding atMostDistinct
Variables
si = 0          // left pointer
ei = 0          // right pointer (exclusive)
count = 0       // number of distinct elements in window
freq[]          // frequency of elements
subArrayCount = 0

Window invariant

At all times:

Window = [si ... ei-1]
count <= k

STEP 3: Dry Run — atMostDistinct(arr, 2)
Iteration 1
ei = 0 → value = 1
freq[1]++ → 1 (new)
count = 1
ei++


Window: [1]

Valid subarrays ending at index 0:

[1]


Count added:

ei - si = 1 - 0 = 1


Total = 1

Iteration 2
ei = 1 → value = 2
freq[2]++ → 1 (new)
count = 2
ei++


Window: [1, 2]

Valid subarrays ending at index 1:

[1,2], [2]


Added:

2 - 0 = 2


Total = 3

Iteration 3
ei = 2 → value = 1
freq[1]++ → 2 (already exists)
count stays 2
ei++


Window: [1,2,1]

Valid subarrays:

[1,2,1], [2,1], [1]


Added:

3 - 0 = 3


Total = 6

Iteration 4
ei = 3 → value = 2
freq[2]++ → 2
count stays 2
ei++


Window: [1,2,1,2]

Valid subarrays:

[1,2,1,2], [2,1,2], [1,2], [2]


Added:

4 - 0 = 4


Total = 10

Iteration 5
ei = 4 → value = 3
freq[3]++ → 1 (new)
count = 3 ❌ (too many)
ei++

Shrink window
remove arr[0] = 1 → freq[1] = 1
count still 3
si = 1

remove arr[1] = 2 → freq[2] = 1
count still 3
si = 2

remove arr[2] = 1 → freq[1] = 0
count = 2
si = 3


Window now:

[2,3]


Valid subarrays ending at index 4:

[2,3], [3]


Added:

5 - 3 = 2


Total = 12

✅ Result
atMostDistinct(arr, 2) = 12

STEP 4: Dry Run — atMostDistinct(arr, 1)

Reset everything.

Iteration Summary
ei	window	count	si	added
0	[1]	1	0	1
1	[2]	1	1	1
2	[1]	1	2	1
3	[2]	1	3	1
4	[3]	1	4	1

Total:

5

STEP 5: Final Calculation
exactly 2 distinct
= 12 − 5
= 7

STEP 6: Why ei - si Is ALWAYS Correct

At any moment:

Window = [si ... ei-1]


All subarrays ending at ei-1:

[si..ei-1]
[si+1..ei-1]
...
[ei-1..ei-1]


Count:

(ei-1) - si + 1 = ei - si


This is the core sliding-window counting invariant.

STEP 7: Key Invariants (Memorize These)

Window always valid before counting

count tracks distinct elements

si only moves forward

Each index enters and leaves window once → O(n)
*/