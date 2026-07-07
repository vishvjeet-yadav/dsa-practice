class Solution {
public:

    int ans,n,m;

    int dfs(int r,int c, vector<vector<int>> &grid, vector<vector<int>> &vis){
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c]==0 || vis[r][c]) return 0;
        vis[r][c]=1;
        int dr[]={-1,1,0,0}, dc[]={0,0,-1,1}, area=1;
        for(int k=0;k<4;k++){
            area+=dfs(r+dr[k],c+dc[k],grid,vis);
        }
        return area;
        
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ans=0, n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    ans = max(ans,dfs(i,j,grid,vis));
                }
            }
        }
        return ans;
    }
};
