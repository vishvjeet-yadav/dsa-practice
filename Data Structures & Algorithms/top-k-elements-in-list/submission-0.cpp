class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto &i:nums) mp[i]++;
        vector<vector<int>> ar(n+1);
        for(auto &i:mp) ar[i.second].push_back(i.first);
        // cout<<"Mp: ";
        
        // for(auto &i: mp ) cout<<i.first<<" : "<<i.second<<endl;
        // cout<<" array : ";
        // for(auto &i:ar) for(auto &j:i) cout<<j<<" --> ";
        for(int i=n;i>=0;i--){
            for(int j=0;j<ar[i].size();j++){
                if(k==0) return ans;
                ans.push_back(ar[i][j]);
                k--;
            }
        }
        
        return ans;
    }

};
