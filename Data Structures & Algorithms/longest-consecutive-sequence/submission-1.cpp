class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &i:nums) mp[i]++;
        int ans=0,cur=0;

        for(auto i:mp){
            if(!mp.count(i.first-1)){
                int k=i.first;
                cur=1;
                while(mp.count(k+1)){
                    k++;
                    cur++;
                }
                ans=max(ans,cur);
            }
        }
        return ans;

    }
};
