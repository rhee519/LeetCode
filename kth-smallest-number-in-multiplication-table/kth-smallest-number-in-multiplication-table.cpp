class Solution {
public:
    pair<int, int> count(int m, int n, int target) {
        // return: {first, second}
        // first == #(nums < target in m*n table)
        // second == #(nums <= target in m*n table)
        pair<int, int> cnt(0, 0);
        for(int i = 1; i <= m; i++) {
            int q = target/i, r = target%i;
            int less = min(q, n);
            cnt.first += less; cnt.second += less;
            if(target <= i*n and r == 0) cnt.first--;
        }
        return cnt;
    }
    
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m*n;
        int mid = (left+right)/2;
        // cout << "m: " << m << ", n: " << n << "\n";
        while(left < right) {
            pair<int, int> cnt = count(m, n, mid);
            // cout << "mid: " << mid << "\n";
            // cout << "cnt: " << cnt.first << " " << cnt.second << "\n";
            if(cnt.first < k and cnt.second >= k) break;
            else if(cnt.first >= k) {
                right = mid;
            } else if(cnt.second < k) {
                left = mid+1;
            }
            mid = (left+right)/2;
        }
        // cout << count(m, n, tar).first << " " << count(m, n, tar).second << "\n";
        return mid;
    }
};