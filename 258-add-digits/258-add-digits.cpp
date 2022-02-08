class Solution {
public:
    int addDigits(int num) {
        // num = a_n * 10^n  + ... a_1 * 10 + a_0
        // if a_0 == 9 then num = a_n + ... + a_1 + a_0 = 0 (mod 9)
        // else             num = a_n + ... + a_1 + a_0 (mod 9)
        return num == 0? 0: num%9? num%9 : 9;
    }
};