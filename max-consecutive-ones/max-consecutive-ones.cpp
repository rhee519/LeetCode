class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0, cnt = 0;
        for(int num: nums) {
            if(num == 1) cnt++;
            else cnt = 0;
            maxCnt = maxCnt > cnt? maxCnt : cnt;
        }
        
        return maxCnt;
    }
};