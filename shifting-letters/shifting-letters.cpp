class Solution {
public:
    char shift(char ch, int offset) {
        return (((ch-'a')+offset)%26)+'a';
    }

    string shiftingLetters(string s, vector<int>& shifts) {
        int sum = 0;
        int size = s.length();
        for(int i = 0; i < size; i++) {
            shifts[i] %= 26;
            sum += shifts[i]; sum %= 26;
        }
        
        for(int i = 0; i < size; i++) {
            s[i] = shift(s[i], sum);
            sum -= shifts[i];
            if(sum < 0) sum += 26;
        }
        
        // cout << shift('z', 1000000) << "\n";
        return s;
    }
};