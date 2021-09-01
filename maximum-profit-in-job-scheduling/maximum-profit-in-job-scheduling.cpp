typedef struct {
    int start, end, profit;
} info;

bool myComp(const info& a, const info& b) {
    // sort info in start-nondecreasing-order
    if(a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int size = startTime.size();
        vector<info> v(size);
        int dp[5 * 10000];
        // dp[i] == max profit after ith job
        
        // sort in startTime-nondecreasing-order
        for(int i = 0; i < size; i++) {
            v[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(v.begin(), v.end(), myComp);
        
        // dynamic programming
        dp[size - 1] = v[size - 1].profit;
        for(int i = size - 2; i >= 0; i--) {
            // next == first idx that can be done after ith job is finished
            int next = i+1;
            while(next < size) {
                if(v[i].end <= v[next].start) break;
                next++;
            }
            if(size <= next) {
                dp[i] = max(v[i].profit, dp[i+1]);
            } else {
                dp[i] = max(v[i].profit + dp[next], dp[i+1]);
            }
        }
        
        return dp[0];
    }
};