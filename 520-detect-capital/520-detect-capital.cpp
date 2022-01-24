class Solution {
public:
    bool isUpper(char ch) {
        return 'A' <= ch and ch <= 'Z';
    }
    
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n == 1) return true;
        bool upper = isUpper(word[0]);
        if(upper) {
            bool secondUpper = isUpper(word[1]);
            for(int i = 2; i < n; i++) {
                if(isUpper(word[i]) != secondUpper)
                    return false;
            }
        } else {
            for(int i = 1; i < n; i++) {
                if(isUpper(word[i]))
                    return false;
            }
        }
        
        return true;
    }
};