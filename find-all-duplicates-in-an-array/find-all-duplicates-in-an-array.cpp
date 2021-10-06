class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer;
        unordered_set<int> dup;
        for(int num: nums) {
            if(dup.count(num)) answer.push_back(num);
            else dup.insert(num);
        }
        
        return answer;
    }
};