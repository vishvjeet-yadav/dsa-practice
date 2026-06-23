class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        auto it= find_if(nums.begin(), nums.end(), [](int x) { return x>=0;});
        if(it==nums.end()) return ans;
        int z=distance(nums.begin(),it);
        cout<<"Sorted vec>> ";
        for(auto i: nums) cout<<i<<" ";
        cout<<endl;
        for(int i=0;i<n-2 && nums[i]<1;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int k = n-1;
            for(int j=i+1;j<n-1;j++){
                while(j<k){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> trp={nums[i],nums[j],nums[k]};
                        ans.push_back(trp);
                        while(k>j && nums[k] == nums[k-1]) k--;
                        while(j<k && nums[j] == nums[j+1]) j++;
                        k--;
                        j++;
                    }else if(nums[i]+nums[j]+nums[k]>0){
                        k--;
                    }else break;
                }
            }
        }
        return ans;
    }
};
