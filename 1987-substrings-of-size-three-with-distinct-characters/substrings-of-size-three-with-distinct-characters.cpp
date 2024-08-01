class Solution {
public:
    int countGoodSubstrings(string s) {
          if (s.size() < 3)
            return 0;
        int front = 0, back = 2;
        int count = 0;
        vector<int> temp(26, 0);
        temp[s[0] - 'a']++;
        temp[s[1] - 'a']++;
        while (back < s.size()) {
            temp[s[back] - 'a']++;
            if (temp[s[front] - 'a'] == 1 && temp[s[front + 1] - 'a'] == 1 &&
                temp[s[front + 2] - 'a'] == 1) {
                count++;
            }
            temp[s[front] - 'a']--;
            front++;
            back++;
        }
        return count;
    }
};