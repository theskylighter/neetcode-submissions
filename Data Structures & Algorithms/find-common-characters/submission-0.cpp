class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> cnt(26, INT_MAX);

        for (string& word : words) {
            vector<int> curCnt(26, 0);
            for (char c : word) {
                curCnt[c - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                cnt[i] = min(cnt[i], curCnt[i]);
            }
        }

        vector<string> res;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                res.push_back(string(1, i + 'a'));
            }
        }

        return res;
    }
};