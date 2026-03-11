class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {

        int slow = nums[0];
        int fast = nums[0];

        // Phase 1 : Detect Cycle
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast)
            break;
        }

        // Phase 2 : Find Cycle Start
        slow = nums[0];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

/*
Approach Explanation

Treat the array like a linked list.

Each index points to the value stored at that index.

index → value → next index

This creates a cycle because one number appears twice.

The start of the cycle is the duplicate number.

------------------------------------------------------------------------
Example

nums

[1,3,4,2,2]

Index → Value mapping

0 → 1
1 → 3
2 → 4
3 → 2
4 → 2

Traversal

0 → 1 → 3 → 2 → 4
            ↑   ↓
            └───┘

Cycle starts at 2

------------------------------------------------------------------------
Phase 1 : Detect Cycle

slow moves 1 step
fast moves 2 steps

Iteration 1

slow = nums[1] = 3
fast = nums[nums[1]] = nums[3] = 2

Iteration 2

slow = nums[3] = 2
fast = nums[nums[2]] = nums[4] = 2

slow == fast → cycle detected

------------------------------------------------------------------------
Phase 2 : Find Cycle Entry

Reset slow to start

slow = nums[0]
fast remains at meeting point

Move both one step

Iteration 1

slow = nums[1] = 3
fast = nums[2] = 4

Iteration 2

slow = nums[3] = 2
fast = nums[4] = 2

They meet at 2

Duplicate number = 2

------------------------------------------------------------------------
Time Complexity

Traversal

O(n)

------------------------------------------------------------------------
Space Complexity

O(1)

------------------------------------------------------------------------
Key Idea

Duplicate number = Cycle entry
*/