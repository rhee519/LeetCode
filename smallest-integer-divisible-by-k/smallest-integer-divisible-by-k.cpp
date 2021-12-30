class Solution {
public:
    int smallestRepunitDivByK(int k) {
        map<int, int> mod;
        int r = 1%k, cnt = 1;
        while(r) {
            cnt++;
            r *= 10; r++; r%= k;
            if(mod.count(r)) return -1;
            else mod[r]++;
        }
        return cnt;
    }
};