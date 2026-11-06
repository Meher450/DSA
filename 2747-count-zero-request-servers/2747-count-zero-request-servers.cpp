class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // Sort logs by request time
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int q = queries.size();

        // Store query time with its original index
        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        // Process queries in chronological order
        sort(sortedQueries.begin(), sortedQueries.end());

        // Track the number of requests made by each server
        vector<int> freq(n + 1, 0);

        // Store answers in original query order
        vector<int> ans(q);

        int left = 0, right = 0;
        int active = 0;
        int m = logs.size();

        for (auto& [time, idx] : sortedQueries) {

            // Add all logs with request time <= query time
            while (right < m && logs[right][1] <= time) {
                int id = logs[right][0];

                // Server becomes active when its frequency changes from 0 to 1
                if (freq[id] == 0) {
                    active++;
                }

                freq[id]++;
                right++;
            }

            // Remove logs outside the current time window
            // Window: [time - x, time]
            while (left < right && logs[left][1] < time - x) {
                int id = logs[left][0];

                freq[id]--;

                // Server becomes inactive when its frequency reaches 0
                if (freq[id] == 0) {
                    active--;
                }

                left++;
            }

            // Servers with zero requests = total servers - active servers
            ans[idx] = n - active;
        }

        return ans;
    }
};

/*
APPROACH:
1. Sort logs by their request timestamps.
2. Store each query along with its original index.
3. Sort queries by time so they can be processed chronologically.
4. Maintain a frequency array:
      freq[id] = Number of requests made by server id
                 within the current time window.
5. Use two pointers:
      right = Adds logs whose timestamps are <= query time.
      left  = Removes logs whose timestamps are < query time - x.
6. Maintain active, representing the number of servers
   having at least one request in the current window.
7. If a server's frequency changes from 0 to 1,
   increment active.
8. If a server's frequency changes from 1 to 0,
   decrement active.
9. Calculate the number of inactive servers:
      ans[idx] = n - active
10. Use the original query index to store answers in
    the same order as the input queries.

WHY THIS WORKS:
For each query time q, we need to examine the inclusive
time interval:

      [q - x, q]

A server is active if it has at least one request
within this interval.

Since logs and queries are sorted by time, the sliding
window only moves forward.

Each log is added once and removed at most once.
Therefore, we avoid repeatedly scanning all logs
for every query.

IMPORTANT:
We use:

      logs[left][1] < time - x

instead of <= because the lower boundary is inclusive.
A log occurring exactly at time - x must remain
inside the current window.

DRY RUN:
Input:
n = 3
logs = [[1,3], [2,6], [1,5]]
x = 5
queries = [10,11]

After sorting logs:
[[1,3], [1,5], [2,6]]

Query = 10
Window = [5,10]

- Add requests at times 3, 5 and 6.
- Remove the request at time 3.
- Active servers = 2 (servers 1 and 2).
- Inactive servers = 3 - 2 = 1.

ans[0] = 1

Query = 11
Window = [6,11]

- No new requests need to be added.
- Remove the request at time 5.
- Server 1 becomes inactive.
- Active servers = 1 (server 2).
- Inactive servers = 3 - 1 = 2.

ans[1] = 2

Output:
[1, 2]

COMPLEXITY:
Let:
m = Number of logs
q = Number of queries
n = Number of servers

Time Complexity:
- Sorting logs: O(m log m)
- Sorting queries: O(q log q)
- Sliding window: O(m + q)
- Total: O(m log m + q log q)

Space Complexity:
- Frequency array: O(n)
- Sorted queries: O(q)
- Answer array: O(q)
- Total auxiliary space: O(n + q)

PATTERN:
Sorting + Sliding Window + Two Pointers + Frequency Array
*/