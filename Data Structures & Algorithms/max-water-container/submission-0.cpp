class Solution {
public:
    int maxArea(vector<int>& h) {

        int ans=0, len=0, br=0, l=0,r=h.size()-1;
        while(l<r){
            len=min(h[l],h[r]);
            br=r-l;
            ans=max(ans,len*br);
            if(h[l]<h[r]) l++;
            else r--;
        }
        return ans;
        
        
    }
};
