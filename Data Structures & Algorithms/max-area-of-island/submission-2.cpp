class Solution {
public:
    int ans,n,m;
    

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(),cur=0,maxx=0;
        vector<int> dr={0,0,1,-1} , dc={1,-1,0,0};
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]){
                    q.push(make_pair(i,j));
                    vis[i][j]=1;
                    cur=1;
                    while(!q.empty()){
                        pair<int,int> node=q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nr=node.first+dr[k];
                            int nc=node.second+dc[k];

                            if(nr<0 || nc<0 || nr>=n || nc>=m || !grid[nr][nc] || vis[nr][nc]){
                                continue;
                            }
                            q.push(make_pair(nr,nc));
                            cur++;
                            vis[nr][nc]=1;
                        }
                    }
                    maxx=max(maxx,cur);
                }
            }
        }
        return maxx;

    }
};
