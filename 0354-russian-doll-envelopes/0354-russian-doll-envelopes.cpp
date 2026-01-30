class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        // Step 1: Sort envelopes
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1]; // height descending for same width
                 return a[0] < b[0];     // width ascending
             });

        // Step 2: Apply LIS on heights
        vector<int> lis;

        for (auto& env : envelopes) {
            int height = env[1];

            // Binary search in LIS array
            auto it = lower_bound(lis.begin(), lis.end(), height);

            if (it == lis.end()) {
                lis.push_back(height);
            } else {
                *it = height;
            }
        }

        // Step 3: Result is LIS length
        return lis.size();
    }
};
