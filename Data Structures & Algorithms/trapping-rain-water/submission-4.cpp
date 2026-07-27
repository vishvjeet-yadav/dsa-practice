
class Solution {
public:
    int trap(vector<int>& h) {
        int ans=0,l=0,r=h.size()-1, lmax=h[l],rmax=h[r];
        
        while(l<r){
            if(lmax<rmax){
                l++;
                lmax=max(lmax,h[l]);
                ans+=lmax-h[l];
            }else{
                r--;
                rmax=max(rmax,h[r]);
                ans+=rmax-h[r];   
            }
        }
        return ans;
    }
    

};
