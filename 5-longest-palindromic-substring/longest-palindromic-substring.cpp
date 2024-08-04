class Solution {
public:
    string longestPalindrome(string s) {
         int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        auto f = [&](auto& f, int i, int j) -> int {
            if (dp[i][j] != -1) return dp[i][j];
            if (i >= j) {
                return dp[i][j] = 1;
            }
            if (s[i] == s[j]) {
                return dp[i][j] = f(f, i + 1, j - 1);
            }
            return dp[i][j] = 0;
        };

        int maxLen = 0;
        int sp = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (f(f, i, j)) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxLen);
    }
};