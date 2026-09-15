class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> arr;

        // Put both arrays into one array
        for (int x : nums1)
            arr.push_back(x);

        for (int x : nums2)
            arr.push_back(x);

        // Sort the combined array
        sort(arr.begin(), arr.end());

        int n = arr.size();

        // Odd number of elements
        if (n % 2 == 1) {
            return arr[n / 2];
        }

        // Even number of elements
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
};