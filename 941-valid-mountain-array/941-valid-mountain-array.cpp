class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int idx = 1, n = arr.size();
        while(idx < n and arr[idx-1] < arr[idx]) idx++;
        if(idx == 1 or idx == n) return false; // no increasing(or decreasing) interval
        while(idx < n and arr[idx-1] > arr[idx]) idx++;
        return idx == n;
    }
};