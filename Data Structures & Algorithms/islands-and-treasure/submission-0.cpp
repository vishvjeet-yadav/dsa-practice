class Solution {
public:

    int n,m;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    vector<vector<int>> vis(n,vector<int>(m,0));
                    queue<pair<pair<int,int>,int>> q;
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    while(!q.empty()){
                        pair<pair<int,int>,int> node=q.front();
                        int r=node.first.first;
                        int c=node.first.second;
                        int dist=node.second;
                        q.pop();

                        int dr[]={-1,1,0,0,}, dc[]={0,0,-1,1};
                        for(int k=0;k<4;k++){
                            if(r+dr[k]<0 || r+dr[k]>=n || c+dc[k]<0 || c+dc[k]>=m || grid[r+dr[k]][c+dc[k]]==-1 || grid[r+dr[k]][c+dc[k]]==0 || vis[r+dr[k]][c+dc[k]]) continue;
                            vis[r+dr[k]][c+dc[k]]=1;
                            grid[r+dr[k]][c+dc[k]]=min(dist+1, grid[r+dr[k]][c+dc[k]]);
                            q.push({{r+dr[k],c+dc[k]},dist+1});
                        }
                    }
                }
            }
        }
    }
};
