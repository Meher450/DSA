class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();              // Get total number of lines
        int start = 0, end = n - 1;         // Initialize two pointers
        int ans = 0;                        // Store maximum area found
        
        while (start < end) {               // Run until pointers meet    
            // Calculate current area = min height × width
            ans = max(ans,min(height[start], height[end]) * (end - start));
            
            // Move pointer at smaller height to try increasing area
            if (height[start] < height[end])
                start++;
            else
                end--;
        }
        return ans;                         // Return maximum area
    }
};

/*
==================== DRY RUN ====================

Input:
height = [1,8,6,2,5,4,8,3,7]
index     0 1 2 3 4 5 6 7 8

Initial:
start = 0
end   = 8
ans   = 0

--------------------------------------------------

Iteration 1:
height[start] = 1
height[end]   = 7
width = 8
area  = min(1,7) * 8 = 8
ans   = 8
Move start (1 < 7)

start = 1, end = 8

--------------------------------------------------

Iteration 2:
height[start] = 8
height[end]   = 7
width = 7
area  = min(8,7) * 7 = 49
ans   = 49
Move end (8 > 7)

start = 1, end = 7

--------------------------------------------------

Iteration 3:
height[start] = 8
height[end]   = 3
width = 6
area  = 3 * 6 = 18
ans   = 49
Move end

start = 1, end = 6

--------------------------------------------------

Iteration 4:
height[start] = 8
height[end]   = 8
width = 5
area  = 8 * 5 = 40
ans   = 49
Move end (equal case → else branch)

start = 1, end = 5

--------------------------------------------------

Iteration 5:
height[start] = 8
height[end]   = 4
width = 4
area  = 4 * 4 = 16
ans   = 49
Move end

start = 1, end = 4

--------------------------------------------------

Iteration 6:
height[start] = 8
height[end]   = 5
width = 3
area  = 5 * 3 = 15
ans   = 49
Move end

start = 1, end = 3

--------------------------------------------------

Iteration 7:
height[start] = 8
height[end]   = 2
width = 2
area  = 2 * 2 = 4
ans   = 49
Move end

start = 1, end = 2

--------------------------------------------------

Iteration 8:
height[start] = 8
height[end]   = 6
width = 1
area  = 6 * 1 = 6
ans   = 49
Move end

start = 1, end = 1

--------------------------------------------------

Loop ends (start == end)

Final Answer:
49

Maximum container formed between:
index 1 (height 8) and index 8 (height 7)
width = 7
area = 7 * 7 = 49

==================================================
*/

/* brute force approach
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,min(height[i],height[j])*(j-i));
            }
        }
        return ans;
    }
*/ 