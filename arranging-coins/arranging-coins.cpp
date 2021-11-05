class Solution {
public:
    int binarySearch(int n, long long low, long long high) {
        long long mid = (low+high)/2;
        long long left = mid*(mid+1)/2, right = (mid+1)*(mid+2)/2;
        if(left <= n and n < right)
            return mid;
        if(n < left) return binarySearch(n, low, mid);
        else return binarySearch(n, mid+1, high);
        
    }
    int arrangeCoins(int n) {
        return binarySearch(n, 1, n);
    }
};