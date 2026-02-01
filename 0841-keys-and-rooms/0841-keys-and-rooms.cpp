class Solution {
public:
    void DFS(vector<vector<int>>&adj,vector<bool>&vis,int node){
        vis[node]=true;
        for(auto &u:adj[node]){
            if(vis[u]==false){
                DFS(adj,vis,u);
            }
        }
    }
    void BFS(vector<vector<int>>&adj,vector<bool>&vis,int node){
        queue<int>q;
        q.push(node);
        vis[node]=true;
        while(!q.empty()){
            node=q.front();
            q.pop();
            for(auto &u:adj[node]){
                if(vis[u]==false){
                    vis[u]=true;
                    q.push(u);
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<vector<int>>adj(n);
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            for(auto &u:rooms[i]){
                adj[i].push_back(u);
            }
        }
        //DFS(adj,vis,0);
        BFS(adj,vis,0);
        for(int i=0;i<n;i++){
            if(vis[i]==false) return false;
        }
        return true;
    }
};