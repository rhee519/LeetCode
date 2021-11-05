class Solution {
public:
    int arrangeCoins(int n) {
        // find k s.t. k(k+1)/2 <= n < (k+1)(k+2)/2
        if(n == 1) return 1;
        long long sum = 0;
        for(int k = 1; k <= n; k++) {
            sum += k;
            if(sum > n) return k-1;
        }
        return 0;
    }
};