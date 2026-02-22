class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        if(arr.empty()) return 0;

        int k = 1;        // The first element is always unique.

        // Start checking from the second element
        for(int i = 1; i < arr.size(); i++) {

            // If current element is different from previous element,
            // it means we found a new unique value.
            if(arr[i] != arr[i - 1]) {

                // Place the unique element at index k
                arr[k] = arr[i];

                // Move k forward to prepare for next unique element
                k++;
            }
        }

        // k is the count of unique elements
        return k;
    }
};


/*
===========================
DRY RUN
===========================

Input:
arr = [1, 1, 2, 2, 3]

Initial:
k = 1
i starts from 1

---------------------------------
Iteration 1:
i = 1
arr[i] = 1
arr[i-1] = 1

1 == 1 → duplicate
Do nothing

Array remains:
[1, 1, 2, 2, 3]
k = 1

---------------------------------
Iteration 2:
i = 2
arr[i] = 2
arr[i-1] = 1

2 != 1 → new unique element found

arr[k] = arr[1] = 2
k++ → k = 2

Array becomes:
[1, 2, 2, 2, 3]

---------------------------------
Iteration 3:
i = 3
arr[i] = 2
arr[i-1] = 2

2 == 2 → duplicate
Do nothing

Array remains:
[1, 2, 2, 2, 3]
k = 2

---------------------------------
Iteration 4:
i = 4
arr[i] = 3
arr[i-1] = 2

3 != 2 → new unique element found

arr[k] = arr[2] = 3
k++ → k = 3

Array becomes:
[1, 2, 3, 2, 3]

---------------------------------

Loop ends.

Return k = 3

Final valid portion of array:
[1, 2, 3]

Elements after index k-1 are irrelevant.
Only first k elements are considered valid.
*/