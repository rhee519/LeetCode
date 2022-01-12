class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(), cnt = n;
        k %= n;
        if(k == 0) return;
        
        int idx = 0;
        while(cnt) {
            int start = idx;
            int src = start;
            int des = (start+k)%n;
            int prev = nums[src];
            while(true) {
                int next = nums[des];
                nums[des] = prev;
                prev = next;
                src = des; des += k; des %= n;
                cnt--;
                if(src == start) break;
            }
            idx++;
        }
    }
};