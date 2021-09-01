class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minR = m, minC = n;
        for(auto op: ops) {
            if(minR > op[0]) minR = op[0];
            if(minC > op[1]) minC = op[1];
        }
        return minR * minC;
    }
};