class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int ,int>m;
        for (int i=0;i<n;i++){
            m[arr[i]]++;

        }
        unordered_set<int >s;
        for (auto b : m ){
            int x = b.second;
            if(s.find(x)!=s.end())  return false;
            else s.insert(x);

                  }
                  return true;

    }
};