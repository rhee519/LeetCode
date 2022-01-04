class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        unsigned int flag = 1<<31;
        int ans = 0;
        while(flag and !(n&flag)) flag >>= 1;
        while(flag) {
            if(!(n&flag)) ans |= flag;
            flag >>= 1;
        }
        return ans;
    }
};