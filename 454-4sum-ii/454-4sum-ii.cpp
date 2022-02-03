class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt = 0;
        unordered_map<int, int> m1, m2;
        
        for(int n1: nums1) {
            for(int n2: nums2) {
                m1[n1+n2]++;
            }
        }
        
        for(int n3: nums3) {
            for(int n4: nums4) {
                m2[n3+n4]++;
            }
        }
        
        for(auto& e1: m1) {
            int sum = e1.first, num = e1.second;
            // (num) tuples (i, j) exist, where i+j == (sum) in nums1 & nums2
            if(m2.count(-sum)) {
                // ((m2[-sum]) tuples (k, l) exist, where k+l == (-sum) in nums3 & nums4)
                cnt += num * m2[-sum];
            }
        }
        
        return cnt;
    }
};