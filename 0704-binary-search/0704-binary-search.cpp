class Solution {
public:
    int search(vector<int>& nums, int target) {
        //two pointers - left and right
        int left = 0;
        int right = nums.size()-1;

        while(left<=right){
            int mid = left + (right-left)/2;//middle pointer
            if (nums[mid]==target){//if middleth element is target
                return mid;//return middle index
            }
            else if (nums[mid]<target){
                left = mid+1;//update left pointer
            }else{
                right = mid-1;//update right pointer
            }
        }

        return -1;
    }
};