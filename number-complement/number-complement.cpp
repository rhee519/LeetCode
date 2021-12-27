class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        unsigned int flag = 1<<31;
        while(flag > num) flag >>= 1;
        while(flag) {
            if(!(flag&num)) ans |= flag;
            flag >>= 1;
        }
        return ans;
    }
};