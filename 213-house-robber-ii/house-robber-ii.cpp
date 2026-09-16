class Solution {
public:

    int solve(vector<int>& nums, int start, int end) {

        vector<int> dp(end - start + 1);

        dp[0] = nums[start];

        if (start == end)
            return dp[0];

        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < dp.size(); i++) {
            dp[i] = max(dp[i - 1],
                        dp[i - 2] + nums[start + i]);
        }

        return dp.back();
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        int firstCase = solve(nums, 0, n - 2);
        int secondCase = solve(nums, 1, n - 1);

        return max(firstCase, secondCase);
    }
};