class Solution {
public:
    int minEatingSpeed(vector<int>& v, int h) {
        int n=v.size(),mid,l=1,r=*(max_element(v.begin(),v.end())),cur=0,ans=INT_MAX;
        while(l<=r){
            cur=0;
            mid=l+((r-l)/2);
            // cout<<" For mid :"<<mid<<" cur:"<<cur<<" minh:"<<minh<<" ans:"<<ans<<" l:"<<l<<" r:"<<r<<endl;
            for(int i=0;i<n;i++){
                cur+=v[i]/mid;
                if(v[i]%mid) cur++;
            }
            if(cur>h) l=mid+1;
            else r=mid-1;
            // cout<<" For mid :"<<mid<<" cur:"<<cur<<" minh:"<<minh<<" ans:"<<ans<<" l:"<<l<<" r:"<<r<<endl;
            if(h>=cur) {
                ans=min(ans,mid);
            }
    }
        return ans;
        
    }
};
