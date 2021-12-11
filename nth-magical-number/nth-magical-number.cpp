class Solution {
public:
    int modulo = 1e9 + 7;
    long long search(int a, int b, int lcm_ab, long long num) {
        // return #(<= num && divisible by either a or b)
        return num/a + num/b - num/lcm_ab;
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        long long left = 1, right = (long long)n*max(a, b), mid = (left+right)/2;
        int lcm_ab = lcm(a, b);
        // cout << "n = " << n << ", a = " << a << ", b = " << b << "\n";
        while(left < right) {
            long long target = search(a, b, lcm_ab, mid);
            // cout << left << " " << right << ", target: " << target << "\n";
            if(target < n) {
                left = mid+1;
            } else if(target > n) {
                right = mid;
            } else { // target == n
                while(mid%a and mid%b) mid--;
                break;
            }
            mid = (left+right)/2;
        }
        return mid % modulo;
    }
};