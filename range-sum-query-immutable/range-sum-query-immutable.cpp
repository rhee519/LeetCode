class NumArray {
private:
    // segment tree
    vector<int> tree;
    int size;
public:
    NumArray(vector<int>& nums) {
        this->size = nums.size();
        this->tree.resize(4 * this->size);
        init(nums, 1, 0, this->size - 1);
    }
    
    int init(vector<int>& nums, int node, int start, int end) {
        // tree[node] == sum of nums[start : end]
        if(start == end) 
            return tree[node] = nums[start];
        
        int mid = (start + end)/2;
        // tree[node*2]     == sum of nums[start : mid]
        // tree[node*2+1]   == sum of nums[mid+1 : end]
        return tree[node] = init(nums, node*2, start, mid) + init(nums, node*2+1, mid+1, end);
    }
    
    int sum(int node, int start, int end, int left, int right) {
        // return partial sum of intersection(start~end, left~right)
        // e.g. start == 4, end == 7, left == 5, right == 8
        // return value : sum of nums[5:7]
        if(end < left || right < start)
            return 0;
        if(left <= start && end <= right)
            return tree[node];
        
        int mid = (start + end)/2;
        return sum(node*2, start, mid, left, right) + sum(node*2+1, mid+1, end, left, right);
    }
    
    int sumRange(int left, int right) {
        return sum(1, 0, size-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */