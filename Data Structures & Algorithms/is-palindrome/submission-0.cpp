class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.length()-1;
        transform(s.begin(), s.end(),s.begin(),[](unsigned char ch){
            return tolower(ch);
        });
        while(i<j){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            // cout<<"checking >>"<<s[i]<<"=="<<s[j]<<endl;
            if(s[i++] !=s[j--]) return false;
            
        }
        return true;
    }
};
