class Solution {
public:
    bool repeatedSubstringPattern(string s) {
         string temp = s + s;
        string check = temp.substr(1, temp.size()-2);
        int ans = check.find(s);
        if(ans == -1){
            return false;
        }
        return true;
    }
};