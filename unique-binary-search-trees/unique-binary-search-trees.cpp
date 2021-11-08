class Solution {
public:
    int numTrees(int n) {
        vector<int> sub(n+1);
        sub[0] = 1; sub[1] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                sub[i] += sub[j-1] * sub[i-j];
            }
        }
        
        return sub[n];
    }
};