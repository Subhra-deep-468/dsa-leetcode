class Solution {
public:
    vector<int> dp;

    int solve(int index, vector<int>& nums) {

        // No houses left
        if (index >= nums.size()) {
            return 0;
        }

        // Already computed
        if (dp[index] != -1) {
            return dp[index];
        }

        // Rob the current house
        int rob = nums[index] + solve(index + 2, nums);

        // Skip the current house
        int skip = solve(index + 1, nums);

        // Store and return the answer
        return dp[index] = max(rob, skip);
    }

    int rob(vector<int>& nums) {

        dp.resize(nums.size(), -1);

        return solve(0, nums);
    }
};