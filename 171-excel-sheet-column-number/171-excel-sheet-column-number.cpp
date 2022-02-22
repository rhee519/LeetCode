class Solution {
public:
    int titleToNumber(string columnTitle) {
        int num = 0;
        for(char ch: columnTitle) {
            num *= 26;
            num += ch-'A'+1;
        }
        return num;
    }
};