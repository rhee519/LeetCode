typedef pair<int, int> pii;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int min_dev = INT_MAX;
        set<int> s;
        for(int num: nums) {
            if(num%2) num <<= 1;
            s.insert(num);
        }
        
        while(*s.rbegin() % 2 == 0) {
            int maximum = *s.rbegin();
            s.erase(maximum);
            maximum >>= 1;
            s.insert(maximum);
            min_dev = min(min_dev, *s.rbegin() - *s.begin());
        }
        
        // for(auto num: s) {
        //     cout << num << " ";
        // } cout << "\n";
        
        return min_dev;
    }
};