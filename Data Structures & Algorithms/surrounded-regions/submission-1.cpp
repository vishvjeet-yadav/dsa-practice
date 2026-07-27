class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int n=grid.size() , m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(grid[i][0]=='O') q.push(make_pair(i,0));
            if(grid[i][m-1]=='O') q.push(make_pair(i,m-1));
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]=='O') q.push(make_pair(0,i));
            if(grid[n-1][i]=='O') q.push(make_pair(n-1,i));
        }

        while(!q.empty()){
            pair<int,int> node=q.front();
            q.pop();
            if(!vis[node.first][node.second]) vis[node.first][node.second]=true;

            int dr[]={0,0,1,-1} , dc[]={1,-1,0,0};
            for(int k=0;k<4;k++){
                int nr=node.first+dr[k];
                int nc=node.second+dc[k];
                if(nr<0 || nc<0 || nr>n-1 || nc>m-1 || grid[nr][nc]=='X' || vis[nr][nc]) continue;
                q.push(make_pair(nr,nc));
                vis[nr][nc]=true;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O' && !vis[i][j]) grid[i][j]='X';
            }
        }

    }
};
