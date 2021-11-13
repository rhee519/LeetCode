class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> idx;
        
        for(int i = 0; i < n; i++) {
            if(!idx.empty() and temperatures[i] > temperatures[idx.top()]) {
                while(!idx.empty()) {
                    int top = idx.top(); 
                    if(temperatures[i] <= temperatures[top]) break;
                    idx.pop();
                    ans[top] = i-top;
                }
            }
            idx.push(i);
        }
        
        return ans;
    }
};