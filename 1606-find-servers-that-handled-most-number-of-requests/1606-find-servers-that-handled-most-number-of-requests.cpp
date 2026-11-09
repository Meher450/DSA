class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        // Min-heap: {finish_time, server_index}
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            busy;

        // Ordered set containing currently available servers
        set<int> available;

        // Initially, all servers are available
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // Count requests handled by each server
        vector<int> count(k, 0);

        // Process requests in arrival order
        for (int i = 0; i < arrival.size(); i++) {

            // Release servers whose requests have completed
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                int id = busy.top().second;
                busy.pop();

                available.insert(id);
            }

            // If all servers are busy, drop the request
            if (available.empty()) {
                continue;
            }

            // Preferred server according to the request index
            int preferred = i % k;

            // Find the first available server >= preferred
            auto it = available.lower_bound(preferred);

            // Wrap around to the smallest available server
            if (it == available.end()) {
                it = available.begin();
            }

            // Assign the request to the selected server
            int id = *it;

            // Remove the server from available servers
            available.erase(it);

            // Increment the server's request count
            count[id]++;

            // Mark the server as busy until arrival + load
            busy.push({arrival[i] + load[i], id});
        }

        // Find the maximum number of requests handled
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        // Return all servers having the maximum request count
        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

/*
APPROACH:
1. Use two data structures to manage servers:

   BUSY MIN-HEAP:
      Stores {finish_time, server_index}.
      Helps identify the server that becomes available
      earliest.

   AVAILABLE ORDERED SET:
      Stores the indices of currently available servers.
      Maintains servers in ascending order.

2. Initially, insert all server indices from 0 to k-1
   into the available set.

3. Process requests in their original order.

4. For every request:
   - Check the busy min-heap.
   - Release all servers whose finish time is less than
     or equal to the current request's arrival time.
   - Insert released servers into the available set.

5. If the available set is empty:
   - All servers are busy.
   - Drop the current request using continue.

6. Calculate the preferred server:
      preferred = i % k

7. Use lower_bound(preferred) to find the smallest
   available server index greater than or equal to
   the preferred server.

8. If lower_bound() returns available.end():
   - No suitable server exists from preferred onward.
   - Wrap around and select available.begin().

9. Assign the request to the selected server:
   - Remove it from the available set.
   - Increment its request count.
   - Insert it into the busy min-heap with its finish time:
         arrival[i] + load[i]

10. After processing all requests:
    - Find the maximum request count.
    - Return all server indices having that count.

WHY THIS WORKS:
The problem requires assigning each request to the
available server with the smallest index that is
greater than or equal to i % k.

If no such server exists, we wrap around and choose
the smallest available server index.

The ordered set maintains server indices in sorted order,
allowing lower_bound() to find the correct server
efficiently.

The min-heap tracks completion times, allowing us to
release completed servers before processing each request.

DRY RUN:
Input:
k = 3
arrival = [1, 2, 3, 4, 5]
load    = [5, 2, 3, 3, 3]

Initially:
Available = {0, 1, 2}
Busy = {}

Request 0:
   Arrival = 1
   Preferred server = 0 % 3 = 0
   Assign server 0.
   Finish time = 1 + 5 = 6.
   Count = [1, 0, 0]

Request 1:
   Arrival = 2
   Preferred server = 1 % 3 = 1
   Assign server 1.
   Finish time = 2 + 2 = 4.
   Count = [1, 1, 0]

Request 2:
   Arrival = 3
   Preferred server = 2 % 3 = 2
   Assign server 2.
   Finish time = 3 + 3 = 6.
   Count = [1, 1, 1]

Request 3:
   Arrival = 4
   Server 1 finishes at time 4.
   Release server 1.

   Preferred server = 3 % 3 = 0.
   Server 0 is busy.
   Server 1 is the next available server.
   Assign server 1.
   Finish time = 4 + 3 = 7.
   Count = [1, 2, 1]

Request 4:
   Arrival = 5
   All servers are busy.
   Drop the request.
   Count = [1, 2, 1]

Maximum request count = 2

Output:
   [1]

COMPLEXITY:
Let:
   k = Number of servers
   n = Number of requests

Time Complexity:
   - Initialize available set: O(k log k)
   - Process requests: O(n log k)
   - Each server is released at most once per request
     assignment, and each heap/set operation takes O(log k).
   - Find maximum count: O(k)
   - Build answer: O(k)

   Overall: O((n + k) log k)

Space Complexity:
   - Available set: O(k)
   - Busy min-heap: O(k)
   - Request count array: O(k)
   - Answer array: O(k)

   Overall: O(k)

PATTERN:
Greedy + Min-Heap + Ordered Set + Scheduling
*/