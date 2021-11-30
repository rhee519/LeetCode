class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() or matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n+1);
        int ans = 0;
        
        for(int i = m-1; i >= 0; i--) {
            stack<int> st;
            for(int j = 0; j <= n; j++) {
                dp[j] = j==n? -1 : matrix[i][j]=='0'? 0 : dp[j]+1;
                while(!st.empty() and dp[st.top()] > dp[j]) {
                    int height = dp[st.top()]; st.pop();
                    int width = st.empty()? j : j-st.top()-1;
                    ans = max(ans, height*width);
                }
                st.push(j);
            }
        }
        return ans;
    }
};

// area: 2 
// st: [1, 2]
// dp: [2, 1, 1, 2]
// h: 
// w: 