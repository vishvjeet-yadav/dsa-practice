class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int pos=0;
        map<vector<int>,vector<string>> strmp;
        vector<int> freq(26,0);
        for(auto s:strs){
            freq.assign(26,0);
            for(int i=0;i<s.length();i++){
                freq[(s[i]-'a')]++;
            }
            strmp[freq].push_back(s);
        }
        for(auto i:strmp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
