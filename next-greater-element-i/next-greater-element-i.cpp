class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> m;
        vector<int> ans(n);
        stack<int> s;
        
        for(int num: nums2) {
            while(!s.empty() and num > s.top()) {
                m[s.top()] = num; s.pop();
            }
            s.push(num);
        }
        
        for(int i = 0; i < n; i++) {
            ans[i] = m.count(nums1[i])? m[nums1[i]] : -1;
        }
        return ans;
    }
};