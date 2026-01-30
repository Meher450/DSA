class Solution {
public:
    int DFS(vector<vector<int>>&matrix, int i,int j, vector<vector<int>>& a, int prev){
        int m=matrix.size();
        int n=matrix[0].size();
        if(i<0 || j<0 || i>=m || j>=n || matrix[i][j]<=prev) return 0;
        
        if(a[i][j]!=0) return a[i][j];

        int left=DFS(matrix,i-1,j,a,matrix[i][j]);
        int right=DFS(matrix,i+1,j,a,matrix[i][j]);
        int top=DFS(matrix,i,j-1,a,matrix[i][j]);
        int bottom=DFS(matrix,i,j+1,a,matrix[i][j]);

        a[i][j]=1 + max({left,right,top,bottom});
        return a[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int>> a(m,vector<int>(n,0));
        int maxi=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxi=max(maxi,DFS(matrix,i,j,a,-1));
            }
        }
    return maxi;
    }
};