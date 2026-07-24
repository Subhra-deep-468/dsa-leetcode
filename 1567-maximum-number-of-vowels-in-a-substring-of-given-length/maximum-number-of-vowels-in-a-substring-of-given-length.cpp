class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {

        int count = 0;

        // Count vowels in the first window
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                count++;
            }
        }

        int ans = count;

        // Slide the window
        for (int i = k; i < s.size(); i++) {

            // Character leaving the window
            if (isVowel(s[i - k])) {
                count--;
            }

            // Character entering the window
            if (isVowel(s[i])) {
                count++;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};