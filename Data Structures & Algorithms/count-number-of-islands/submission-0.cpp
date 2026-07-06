class Solution {
public:
int n,m;
void dfs(int r,int c, vector<vector<int>> &vis,vector<vector<char>> & grid){
    if(r>=n || r<0 || c>=m || c<0) return;
    if(vis[r][c]) return;

    vis[r][c]=1;
    if(grid[r][c]=='0') return; 

    dfs(r+1,c,vis,grid); //down
    dfs(r-1,c,vis,grid); //up
    dfs(r,c+1,vis,grid); //right
    dfs(r,c-1,vis,grid); //left
}
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size(), m=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(grid[i][j]=='1'){
                        ans++;
                        dfs(i,j,vis,grid);
                    } else{
                        vis[i][j]=1;
                    }
                }
            }
        }
        return ans;

    }
};
