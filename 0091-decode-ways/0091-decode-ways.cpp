class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;

        //first char
        dp[1] = (s[0]!='0');

        for (int i=2; i<=n; i++){
            //one digit
            if (s[i-1]!='0')
                dp[i] += dp[i-1];

            //two digits
            int num = (s[i-2]-'0')*10 + (s[i-1]-'0');

            if (num>=10 && num<=26)
                dp[i] += dp[i-2];
        }
        return dp[n];
    }
};