class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<int> freq(26, 0);
        vector<bool> visited(26, false);

        // Count frequency of each character.
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string ans = "";

        for (char ch : s) {

            // One occurrence is being processed.
            freq[ch - 'a']--;

            // If already present in the answer, skip it.
            if (visited[ch - 'a']) {
                continue;
            }

            // Remove larger characters if they appear later.
            while (!ans.empty() &&
                   ans.back() > ch &&
                   freq[ans.back() - 'a'] > 0) {

                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            // Add current character.
            ans.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return ans;
    }
};