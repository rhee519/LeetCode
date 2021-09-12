class Solution {
public:
    string trim(string str) {
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == ' ') str.erase(i--, 1);
        }
        return str;
    }
    
    bool isNum(char ch) {
        return '0' <= ch && ch <= '9';
    }
    
    int calculate(string s) {
        s = trim(s);
        return recursiveCalculate(s);
    }
    
    int recursiveCalculate(string s) { // s is trimmed
        int ret = 0, pos = 0;
        
        int sign = 1;
        while(pos < s.size()) {
            int nextPos = pos + 1;
            int num;
            if(isNum(s[pos])) {
                while(nextPos < s.size() && isNum(s[nextPos])) nextPos++;
                num = sign * stoi(s.substr(pos, nextPos-pos));
                ret += num;
                // cout << num << " ";
            } else if(s[pos] == '(') {
                int cnt = 1;
                while(cnt) {
                    if(s[nextPos] == '(') cnt++;
                    else if(s[nextPos] == ')') cnt--;
                    nextPos++;
                }
                num = sign * recursiveCalculate(s.substr(pos+1, nextPos-pos-2));
                ret += num;
            } else if(s[pos] == '+') {
                sign = 1;
            } else if(s[pos] == '-') {
                sign = -1;
            }
            
            pos = nextPos;
        }
        
        // for(int num: nums) {
        //     // cout << num << " ";
        //     ret += num;
        // }
        // cout << "\n";
        return ret;
    }
};