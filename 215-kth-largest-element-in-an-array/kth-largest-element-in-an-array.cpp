
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // Max heap
        priority_queue<int> pq;


        // Insert all elements
        for(int n : nums)
        {
            pq.push(n);
        }


        // Remove k-1 largest elements
        while(k > 1)
        {
            pq.pop();
            k--;
        }


        // kth largest element
        return pq.top();
    }
};