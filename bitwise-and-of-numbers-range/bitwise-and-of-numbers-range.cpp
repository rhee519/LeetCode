class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result = 0, bit = 1;
        while(left) {
            if(left == right and left%2) result |= bit;
            left >>= 1; right >>= 1; bit <<= 1;
        }
        return result;
    }
};