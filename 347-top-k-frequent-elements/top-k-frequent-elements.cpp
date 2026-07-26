class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Count frequency
        for (int n : nums) {
            freq[n]++;
        }


        // Max heap
        priority_queue<pair<int,int>> pq;


        // Store {frequency, number}
        for (auto it : freq) {
            pq.push({it.second, it.first});
        }


        vector<int> ans;


        // Take top k elements
        while (k--) {

            ans.push_back(pq.top().second);
            pq.pop();

        }

        return ans;
    }
};