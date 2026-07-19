class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num:nums){
            pq.push(num);//insert element
            if (pq.size()>k)
                pq.pop();//remove element
        }

        return pq.top();//return top of queue
    }
};