class Solution {
public:
    int partialMin(vector<int>& nums, int left, int right) {
        // return min of nums[left:right]
        int mid = (left+right)/2;
        // printf("left: %d, right: %d --> mid: %d\n", left, right, mid);
        // printf("nums[%d] == %d, nums[%d] == %d\n", left, nums[left], right, nums[right]);
        if(left == right) return nums[left];
        if(nums[left] < nums[right]) return nums[left];
        
        return min(partialMin(nums, left, mid), partialMin(nums, mid+1, right));
    }
    
    int findMin(vector<int>& nums) {
        return partialMin(nums, 0, nums.size()-1);
    }
};