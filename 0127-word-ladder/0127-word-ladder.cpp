class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> myset(wordList.begin(), wordList.end());

        if (myset.find(endWord) == myset.end())
            return 0;

        queue<string> q;
        q.push(beginWord);

        int depth = 1;

        while (!q.empty()) {

            int lsize = q.size();

            while (lsize--) {

                string curr = q.front();
                q.pop();

                for (int i = 0; i < curr.length(); i++) {

                    string temp = curr;

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        temp[i] = ch;

                        if (temp == curr)
                            continue;

                        if (temp == endWord)
                            return depth + 1;

                        if (myset.find(temp) != myset.end()) {
                            q.push(temp);
                            myset.erase(temp); // mark visited
                        }
                    }
                }
            }

            depth++;
        }

        return 0;
    }
};