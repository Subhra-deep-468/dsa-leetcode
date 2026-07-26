class Solution {
public:

    struct compare
    {
        bool operator()(pair<int,int>& a, pair<int,int>& b)
        {
            if(a.first != b.first)
            {
                return a.first > b.first;
            }

            return a.second < b.second;
        }
    };


    vector<int> frequencySort(vector<int>& nums)
    {
        unordered_map<int,int> freq;


        // Count frequency
        for(int n : nums)
        {
            freq[n]++;
        }


        // Min heap with custom comparator
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       compare> pq;


        // Push {frequency, number}
        for(auto it : freq)
        {
            pq.push({it.second, it.first});
        }


        vector<int> ans;


        while(!pq.empty())
        {
            int frequency = pq.top().first;
            int number = pq.top().second;

            pq.pop();


            while(frequency--)
            {
                ans.push_back(number);
            }
        }


        return ans;
    }
};