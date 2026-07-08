class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=1,ans=0, n=prices.size();
        while(r<n){
            ans=max(ans,prices[r]-prices[l]);
            if(prices[r]<prices[l]) l=r;
            r++;
        }
        return ans;
    }
};
