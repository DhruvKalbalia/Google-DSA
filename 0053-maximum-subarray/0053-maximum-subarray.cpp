class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);//create dp array

        dp[0]=nums[0];
        int ans=dp[0];//create ans integer

        for (int i=1;i<n;i++){
            dp[i] = max(nums[i],dp[i-1]+nums[i]);
            //max sum subaarray
            ans = max(ans,dp[i]);
        }

        return ans;
    }
};