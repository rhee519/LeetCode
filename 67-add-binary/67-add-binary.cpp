class Solution {
public:
    int addbit(int a, int b, int& carry) {
        // a, b, carry == 0 | 1
        int sum = a^b^carry;
        carry = (carry&(a|b))|(a&b);
        return sum;
    }
    string addBinary(string a, string b) {
        string ans = "";
        int len = max(a.size(), b.size());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        a.resize(len, '0');
        b.resize(len, '0');
        // cout << a << "\n" << b << "\n";
        int carry = 0;
        for(int i = 0; i < len; i++) {
            int bit1 = a[i]-'0', bit2 = b[i]-'0';
            int sum = addbit(bit1, bit2, carry);
            // cout << "sum: " << sum << "\n";
            // cout << "carry: " << carry << "\n";
            ans = to_string(sum) + ans;
        }
        if(carry) ans = "1" + ans;
        return ans;
    }
};