class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int currentLength = 1;
        int maxLength = 1;

        for (int i = 1; i < nums.size(); i++) {

            // If the current element is greater than the previous one,
            // the increasing sequence continues.
            if (nums[i] > nums[i - 1]) {
                currentLength++;
            }
            // Otherwise, start a new increasing sequence.
            else {
                currentLength = 1;
            }

            // Update the maximum length found so far.
            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};