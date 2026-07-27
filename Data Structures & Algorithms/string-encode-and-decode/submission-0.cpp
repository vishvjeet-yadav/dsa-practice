class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(auto &i:strs){
            for(auto &j:i){
                j++;
                s+=j;
            }
            s+='\n';
        }
        cout<<" encoded s:"<<s<<endl;
        return s;
    }

    vector<string> decode(string s) {
        string st="";
        vector<string> ans;
        for(auto &i:s){
            if(i=='\n'){
                ans.push_back(st);
                st="";
            }else{
                i--;
                st+=i;
            }
        }
        return ans;

    }
};
