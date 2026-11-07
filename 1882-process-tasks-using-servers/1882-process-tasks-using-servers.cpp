class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // Available servers: {weight, server_index}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> available;

        // Busy servers: {finish_time, server_index}
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busy;

        int n = servers.size();
        int m = tasks.size();

        vector<int> ans(m);

        // Initially, all servers are available
        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        long long time = 0;

        for (int i = 0; i < m; i++) {

            // Current task becomes available at time i
            time = max(time, (long long)i);

            // Release all servers whose tasks are completed
            while (!busy.empty() && busy.top().first <= time) {
                auto [finishTime, id] = busy.top();
                busy.pop();

                available.push({servers[id], id});
            }

            // If no server is available, advance time
            if (available.empty()) {
                time = busy.top().first;

                // Release all servers that finish at this time
                while (!busy.empty() && busy.top().first <= time) {
                    auto [finishTime, id] = busy.top();
                    busy.pop();

                    available.push({servers[id], id});
                }
            }

            // Select the server with minimum weight,
            // breaking ties using the smaller index
            auto [weight, id] = available.top();
            available.pop();

            // Assign the current task to this server
            ans[i] = id;

            // Store its completion time
            busy.push({time + tasks[i], id});
        }

        return ans;
    }
};

/*
APPROACH:
1. Use two min-heaps to manage server availability.

2. AVAILABLE MIN-HEAP:
   Stores:
      {server_weight, server_index}

   Selects the server with:
      - Minimum weight.
      - Smallest index when weights are equal.

3. BUSY MIN-HEAP:
   Stores:
      {finish_time, server_index}

   Helps identify which server becomes available next.

4. Initially, insert all servers into the available heap.

5. Process tasks in their original order.

6. For each task:
   - Update the current time to at least the task index.
   - Move all completed servers from the busy heap
     to the available heap.
   - If no server is available, advance time to the
     earliest server completion time.
   - Release all servers that have completed by that time.
   - Select the best available server.
   - Assign the task and record its server index.
   - Calculate its completion time:
         time + tasks[i]
   - Insert the server into the busy heap.

7. Return the assigned server indices.

WHY TWO MIN-HEAPS?
The problem requires two different priorities:

AVAILABLE SERVERS:
   Choose the server with the smallest weight.
   If weights are equal, choose the smallest index.

BUSY SERVERS:
   Choose servers based on the earliest completion time.

A single heap cannot efficiently maintain both priorities.

DRY RUN:
Input:
servers = [3, 3, 2]
tasks = [1, 2, 3, 2, 1, 2]

Initial available servers:
   (2, 2), (3, 0), (3, 1)

Task 0:
   Time = 0
   Select server 2 (weight 2).
   Completion time = 0 + 1 = 1.

Task 1:
   Time = 1
   Server 2 becomes available.
   Select server 2.
   Completion time = 1 + 2 = 3.

Task 2:
   Time = 2
   All servers are busy.
   Earliest completion time = 1? 
   Server 2 actually completes at time 3.
   Advance time to 3.
   Select server 2.
   Completion time = 3 + 3 = 6.

Task 3:
   Time = 3
   Servers 0 and 1 are available.
   Select server 0 (weight 3, smaller index).
   Completion time = 3 + 2 = 5.

Task 4:
   Time = 4
   Server 1 is available.
   Select server 1.
   Completion time = 4 + 1 = 5.

Task 5:
   Time = 5
   Servers 0 and 1 become available.
   Select server 0 (smaller index).
   Completion time = 5 + 2 = 7.

Output:
   [2, 2, 2, 0, 1, 0]

COMPLEXITY:
Let:
   n = Number of servers
   m = Number of tasks

Time Complexity:
   - Building available heap: O(n log n)
   - Processing tasks: O(m log n)
   - Each server enters and leaves the heaps
     a bounded number of times per task.

   Overall: O(n log n + m log n)

Space Complexity:
   - Available heap: O(n)
   - Busy heap: O(n)
   - Answer array: O(m)

   Overall: O(n + m)

PATTERN:
Greedy + Two Min-Heaps + Priority Queue + Scheduling
*/