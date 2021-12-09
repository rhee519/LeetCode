class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visit(n);
        queue<int> q;
        if(arr[start] == 0) return true;
        q.push(start);
        visit[start] = true;
        while(!q.empty()) {
            int pos = q.front(); q.pop();
            int front = pos-arr[pos];
            int back = pos+arr[pos];
            if(0 <= front and !visit[front]) {
                if(arr[front] == 0) return true;
                q.push(front); visit[front] = true;
            }
            if(back < n and !visit[back]) {
                if(arr[back] == 0) return true;
                q.push(back); visit[back] = true;
            }
        }
        return false;
    }
};