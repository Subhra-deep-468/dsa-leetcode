class Solution {
public:
    int solve(vector<int>& nums, int index, int sum, int target,
              vector<vector<int>>& dp) {

        // Base case: all numbers have been used
        if (index == nums.size()) {
            return (sum == target) ? 1 : 0;
        }

        // If this state has already been computed, return it
        if (dp[index][sum + 1000] != -1) {
            return dp[index][sum + 1000];
        }

        // Put '+' before the current number
        int add = solve(nums,
                        index + 1,
                        sum + nums[index],
                        target,
                        dp);

        // Put '-' before the current number
        int subtract = solve(nums,
                             index + 1,
                             sum - nums[index],
                             target,
                             dp);

        // Store and return the total number of ways
        return dp[index][sum + 1000] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // DP table initialized with -1 (not computed)
        vector<vector<int>> dp(nums.size(),
                               vector<int>(2001, -1));

        // Start from index 0 with current sum = 0
        return solve(nums, 0, 0, target, dp);
    }
};