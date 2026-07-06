class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0, cnt=0,fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    // vis[i][j]=1;
                }else if(grid[i][j]==1) fresh++;
                else vis[i][j]=1;
            }
        }
        while(!q.empty()){
            pair<pair<int,int>,int> node=q.front();
            q.pop();
            int cr=node.first.first;
            int cc=node.first.second;
            int ct=node.second;
            
            if(cr<0||cr>=n||cc<0||cc>=m || vis[cr][cc]) continue;
            if(ct>ans) ans=ct;
            vis[cr][cc]=1;
            if(grid[cr][cc]==1) cnt++;
            q.push({{cr-1,cc},ct+1}); //up
            q.push({{cr+1,cc},ct+1}); //down
            q.push({{cr,cc-1},ct+1}); //left
            q.push({{cr,cc+1},ct+1}); //right


        }
        if(cnt!=fresh) return -1;
        return ans;

    }
};
