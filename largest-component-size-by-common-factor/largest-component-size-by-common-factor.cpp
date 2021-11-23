class Solution {
public:
    unordered_map<int, int> root;
    int find(int x) {
        if(!root.count(x)) return root[x] = x;
        if(root[x] == x) return x;
        return root[x] = find(root[x]);
    }
    void _union(int x, int y) {
        x = find(x); y = find(y);
        root[y] = x;
    }
    
    int largestComponentSize(vector<int>& nums) {
        unordered_map<int, int> size;
        int ans = 0, n = nums.size();
        for(int& num: nums) {
            for(int d = 2; d*d <= num; d++) {
                if(num%d == 0) {
                    _union(d, num);
                    _union(num/d, num);
                }
            }
        }
        
        for(int& num: nums) {
            int parent = find(num);
            size[parent]++;
            ans = max(ans, size[parent]);
        }
        
        
        // for(int& num: nums) cout << root[num] << " "; cout << "\n\n";
        
        return ans;
    }
};