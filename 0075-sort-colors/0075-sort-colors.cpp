class Solution {
public:
    void sortColors(vector<int>& arr2) {
        int n2 = arr2.size();

    int ptr21 = 0;          // low
    int itr2  = 0;          // mid
    int ptr22 = n2 - 1;     // high

    while (itr2 <= ptr22) {
        if (arr2[itr2] == 0) {
            swap(arr2[ptr21++], arr2[itr2++]);
        }
        else if (arr2[itr2] == 2) {
            swap(arr2[itr2], arr2[ptr22--]);
        }
        else { // arr2[itr2] == 1
            itr2++;
        }
    }
    }
};