class Solution {
public:
    int solve(int i, string& s, vector<int>& dp) {

        // Reached the end
        if (i == s.size())
            return 1;

        // String cannot start with 0
        if (s[i] == '0')
            return 0;

        // Already calculated
        if (dp[i] != -1)
            return dp[i];

        // Take one digit
        int ans = solve(i + 1, s, dp);

        // Take two digits
        if (i + 1 < s.size()) {

            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

            if (num >= 10 && num <= 26)
                ans += solve(i + 2, s, dp);
        }

        return dp[i] = ans;
    }

    int numDecodings(string s) {

        int n = s.size();

        vector<int> dp(n, -1);

        return solve(0, s, dp);
    }
};