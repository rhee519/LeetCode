class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int maxLen = 1, n = arr.size();
        vector<int> odd(n), even(n);
        // odd[i]: max length (odd) > (even) of arr[0:i]
        // even[i]: max length (odd) < (even) of arr[0:i]
        odd[0] = even[0] = 1;
        for(int i = 1; i < n; i++) {
            if(arr[i-1] < arr[i]) {
                if(i%2) {   // i is odd
                    odd[i] = odd[i-1]+1; even[i] = 1;
                } else {    // i is even
                    odd[i] = 1; even[i] = even[i-1]+1;
                }
            } else if(arr[i-1] > arr[i]) {
                if(i%2) {   // i is odd
                    odd[i] = 1; even[i] = even[i-1]+1;
                } else {    // i is even
                    odd[i] = odd[i-1]+1; even[i] = 1;
                }
            } else { // arr[i-1] = arr[i]
                odd[i] = even[i] = 1;
            }
            maxLen = max(maxLen, max(odd[i], even[i]));
        }
        
        return maxLen;
    }
};