class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        int a = 0, b = (int)sqrt(c);
        
        cout << a << " " << b << "\n";
        while(a <= b) {
            long long sum = (long long)a*a + b*b;
            if(sum == (long long)c) return true;
            else if(sum < (long long)c) a++;
            else b--;
        }
        
        return false;
    }
};