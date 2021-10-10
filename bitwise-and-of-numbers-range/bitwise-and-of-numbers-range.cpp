class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result = 0, bit = 1;
        while(left) {
            if(left == right && left%2) result |= bit;
            left = left>>1; right = right>>1; bit = bit<<1;
        }
        return result;
    }
};