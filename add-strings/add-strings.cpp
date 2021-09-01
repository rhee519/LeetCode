class Solution {
public:
    int adder(int& carry, int a, int b) {
        int ret = carry + a + b;
        carry = ret / 10;
        return ret % 10;
    }
    
    string addStrings(string num1, string num2) {
        string ans = "";
        int len1 = num1.length();
        int len2 = num2.length();
        int maxLen = max(len1, len2);
        
        // reverse num1, num2
        // ex. num1 = "1234" ,  num2 = "12345"
        // =>  num1 = "43210",  num2 = "54321"
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if(len1 > len2) {
            num2.resize(maxLen, '0');
        } else {
            num1.resize(maxLen, '0');
        }
        ans.resize(maxLen, '0');
        
        // full adder
        int carry = 0;
        for(int i = 0; i < maxLen; i++) {
            int a = num1[i] - '0'; int b = num2[i] - '0';
            int ret = adder(carry, a, b);
            ans.at(i) = ret + '0';
        }
        // check MSD
        if(carry) ans += "1";
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};