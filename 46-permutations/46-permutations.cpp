class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        while(true) {
            ans.push_back(nums);
            if(!next_permutation(nums.begin(), nums.end()))
                break;
        }
        
        return ans;
    }
};