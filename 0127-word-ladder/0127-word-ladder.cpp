class Solution {
public:
    // string isPresent(int i, string str, set<string>& s) {
    //     char original = str[i];
    //     for (char ch = 'a'; ch <= 'z'; ++ch) {
    //         if (ch == original) continue;
    //         str[i] = ch;
    //         if (s.find(str) != s.end()) {
    //             return str;
    //         }
    //     }
    //     return "";
    // }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s(wordList.begin(), wordList.end());
        if (s.find(endWord) == s.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            string str = q.front().first;
            int count = q.front().second;
            q.pop();
            for (int i = 0; i < str.size(); i++) {
                string original = str;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (str[i] == ch) continue;
                    str[i] = ch;
                    if (str == endWord) {
                        return count + 1;
                    }
                    if (s.find(str) != s.end()) {
                        s.erase(str);
                        q.push({str, count + 1});
                    }
                }
                str = original;
            }
        }
        return 0;
    }
};