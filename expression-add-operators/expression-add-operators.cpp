class Solution {
public:
    vector<string> ans;
    vector<string> addOperators(string num, int target) {
        dfs(num, "", target, 0, 0, 0);
        return ans;
    }
    void dfs(string num, string expression, int target, int idx, long int res, long int last) {
        if(idx == num.size()) {
            if(res == target) ans.push_back(expression);
            return;
        }
        
        string sub = "";
        long int number = 0;
        
        for(int i = idx; i < num.size(); i++) {
            sub += num[i];
            number *= 10; number += (num[i] - '0');
            if(sub.size() > 1 && sub[0] == '0') break;
            if(idx == 0) { // 수식의 첫번째 수
                dfs(num, sub, target, i+1, number, number);
            } else {
                // add
                dfs(num, expression+"+"+sub, target, i+1, res+number, number);
                // sub
                dfs(num, expression+"-"+sub, target, i+1, res-number, -number);
                // mul
                dfs(num, expression+"*"+sub, target, i+1, res-last+(last*number), last*number);
            }
        }
    }
};