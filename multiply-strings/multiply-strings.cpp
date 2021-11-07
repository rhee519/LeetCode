class Solution {
public:
    char add1bit(char a, char b, int& carry) {
        int sum = (a-'0') + (b-'0') + carry;
        carry = sum/10; sum %= 10;
        return sum+'0';
    }
    
    string add(string& num1, string& num2) {
        int i = num1.size(), j = num2.size(), len;
        if(i > j) {
            len = num1.size();
            reverse(num2.begin(), num2.end());
            num2.resize(len, '0');
            reverse(num2.begin(), num2.end());
        } else {
            len = num2.size();
            reverse(num1.begin(), num1.end());
            num1.resize(len, '0');
            reverse(num1.begin(), num1.end());        
        }
        
        string result = ""; result.resize(len);
        int carry = 0;
        
        for(int i = len-1; i >= 0; i--) {
            result[i] = add1bit(num1[i], num2[i], carry);
        }
        if(carry) result = "1" + result;
        return result;
    }
    
    string multiply(string num1, string num2) {
        string result = "";
        vector<string> table(10);
        table[0] = "0"; table[1] = num2;
        string tmp = num2;
        for(int i = 2; i < 10; i++) {
            tmp = add(tmp, num2); table[i] = tmp;
        }
        
        for(int i = 0; i < num1.size(); i++) {
            result += "0";
            result = add(result, table[num1[i]-'0']);
        }
        
        if(result[0] == '0') result = "0";
        return result;
    }
};