class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int index, vector<int>& temp) {

        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Take the current element
        temp.push_back(nums[index]);
        solve(nums, index + 1, temp);

        // Backtrack
        temp.pop_back();

        // Skip duplicate elements
        int next = index + 1;
        while (next < nums.size() && nums[next] == nums[index]) {
            next++;
        }

        // Don't take the current element
        solve(nums, next, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> temp;

        solve(nums, 0, temp);

        return ans;
    }
};