class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;//left pointer
        int right = *max_element(piles.begin(),piles.end());//right pointer

        while(left<right){
            int mid = left+(right-left)/2;
            if (canFinish(piles,h,mid))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }

    bool canFinish(vector<int>& piles, int h, int speed){
        long long hours = 0;

        for (int bananas: piles){
            hours+=(bananas+speed-1)/speed;//ceil(bananas/speed)
        }

        return hours<=h;
    }
};