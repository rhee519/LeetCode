class Solution {
public:
    int EMPTY = -1;
    void check(vector<int>& a, vector<int>& b) {
        if(a[0] <= b[0] and b[1] <= a[0]) {
            b[0] = b[1] = EMPTY;
        } else if(b[0] <= a[0] and a[1] <= b[1]) {
            a[0] = a[1] = EMPTY;
        }
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        
        // check if one is covered by another
        for(int i = 0; i < intervals.size(); i++) {
            for(int j = 0; j < intervals.size(); j++) {
                if(i == j) continue;
                check(intervals[i], intervals[j]);
            }
        }
        
        // count existing intervals
        for(auto interval: intervals) {
            if(interval[0] != -1 and interval[1] != -1)
                cnt++;
        }
        return cnt;
    }
};