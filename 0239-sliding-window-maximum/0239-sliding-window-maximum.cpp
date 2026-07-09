class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans; //ans vector

        for (int i=0; i<nums.size(); i++){
            //remove out of window
            if (!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            //remove smaller elements
            while(!dq.empty() && nums[dq.back()]<= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            //window complete
            if (i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};