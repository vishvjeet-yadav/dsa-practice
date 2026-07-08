class Solution {
public:

    int n,m;

    bool dfs(int r,int c,vector<vector<int>> &vis,vector<vector<int>> &block,vector<vector<int>> &h, int tr, int tc){
        if(r<0 || c<0 || r>=n || c>=m || vis[r][c] || block[r][c]) return false;
        vis[r][c]=1;
        if(r==tr || c==tc) return true;
        int dr[]={-1,1,0,0}, dc[]={0,0,-1,1};
        bool p=false;
        for(int k=0;k<4;k++){
            // cout<<"For cell : "<<r<<":"<<c<<"checking : "<<endl;
            if(r+dr[k]<0 || c+dc[k]<0 || r+dr[k]>=n || c+dc[k]>=m || vis[r+dr[k]][c+dc[k]] || block[r+dr[k]][c+dc[k]]) continue;
            if(h[r][c] >= h[r+dr[k]][c+dc[k]]){
                p = p || dfs(r+dr[k],c+dc[k],vis,block,h, tr,tc);
            }
        }
        return p;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& ht) {
        n=ht.size(), m=ht[0].size();
        vector<vector<int>> ans, blockA(n,vector<int>(m,0)), blockP(n,vector<int>(m,0)), vis;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<"Checking for : "<<i<<" : "<<j<<" blockP:"<<blockP[i][j]<<" blockA:"<<blockA[i][j]<<endl;
                if(blockA[i][j] || blockP[i][j]) continue;
                vis.assign(n,vector<int>(m,0));
                bool canP=dfs(i,j,vis,blockP,ht,0,0);
                if(!canP) blockP[i][j]=1;
                // cout<<"Possible Pacific : "<<canP<<endl;
                vis.assign(n,vector<int>(m,0));
                bool canA= dfs(i,j,vis,blockA,ht,n-1,m-1);
                if(!canA) blockA[i][j]=1;
                // cout<<"Possible atlantic : "<<canA<<endl;
                if(canA && canP){
                    ans.push_back({i,j});
                }
                // cout<<"Final block P : "<<endl;
                // for(int k=0;k<n;k++){
                //     for (int l=0;l<m;l++){
                //         cout<<blockP[k][l]<<" ";
                //     }
                //     cout<<endl;
                // }
                // cout<<"Final block A : "<<endl;
                // for(int k=0;k<n;k++){
                //     for (int l=0;l<m;l++){
                //         cout<<blockA[k][l]<<" ";
                //     }
                //     cout<<endl;
                // }
                
            }
        }
        return ans;

    }
};
