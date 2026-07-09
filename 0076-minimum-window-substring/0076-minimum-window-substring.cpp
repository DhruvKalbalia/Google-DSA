class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;

        for (char ch:t){
            mp[ch]++;
        }
        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        int required = t.size();

        for (int right = 0; right<s.size(); right++){
            if (mp[s[right]]>0)
                required--;

            mp[s[right]]--;

            while(required==0){
                if(right-left+1<minLen){
                    minLen = right - left + 1;
                    start = left;
                }

                mp[s[left]]++;

                if (mp[s[left]]>0)
                    required ++;

                left++;
            }
        }
        return minLen == INT_MAX? "":s.substr(start,minLen);
    }
};