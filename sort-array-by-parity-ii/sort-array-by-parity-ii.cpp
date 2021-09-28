class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> wrongEven, wrongOdd;
        for(int i = 0; i < nums.size(); i++) {
            if(i%2 and !(nums[i]%2)) wrongOdd.push_back(i);
            else if(!(i%2) and nums[i]%2) wrongEven.push_back(i);
        }
        if(wrongEven.size() != wrongOdd.size()) return vector<int>();
        
        while(wrongEven.size()) {
            int i = wrongEven.back(), j = wrongOdd.back();
            wrongEven.pop_back(); wrongOdd.pop_back();
            swap(nums[i], nums[j]);
        }
        
        return nums;
    }
};