class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0; 

        // stop -> list of routes that pass through it
        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }

        queue<int> q;                       // BFS over routes
        unordered_set<int> visitedRoutes;   // routes already taken

        // Initialize BFS with all routes containing the source stop
        for (int route : stopToRoutes[source]) {
            q.push(route);
            visitedRoutes.insert(route);
        }

        int busesTaken = 1;

        while (!q.empty()) {
            int levelSize = q.size();

            while (levelSize--) {
                int route = q.front();
                q.pop();

                // Explore all stops in the current route
                for (int stop : routes[route]) {
                    if (stop == target) {
                        return busesTaken;
                    }

                    // From each stop, explore connected routes
                    for (int nextRoute : stopToRoutes[stop]) {
                        if (!visitedRoutes.count(nextRoute)) {
                            visitedRoutes.insert(nextRoute);
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busesTaken++;
        }

        return -1;
    }
};