class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>,vector<string>> mp;
        vector<int> freq(26,0);
        for(auto s:strs){
            freq.assign(26,0);
            for(int i=0;i<s.length();i++){
                freq[(s[i]-'a')]++;
            }
            mp[freq].push_back(s);
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
