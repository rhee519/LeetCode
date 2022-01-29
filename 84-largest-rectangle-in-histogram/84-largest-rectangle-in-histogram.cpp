class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> st;
        heights.push_back(0);
        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() and heights[st.top()] >= heights[i]) {
                int height = heights[st.top()];
                st.pop();
                int start = st.empty()? -1 : st.top();
                int width = i-1-start;
                ans = max(ans, height*width);
            }
            st.push(i);
        }
        return ans;
    }
};