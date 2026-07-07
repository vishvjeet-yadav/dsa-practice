class Solution {
public:
    

    void dfs(int node,vector<int> &vis, vector<vector<int>> & adj){
        if(vis[node]) return;
        vis[node]=1;
        for(auto &i:adj[node]){
            if(!vis[i]){
                dfs(i,vis,adj);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& ed) {
        int ans=0;
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(auto &i:ed){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                ans++;
            }
        }
        return ans;
    }
};
