class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[5] = {0, };
        // cnt[0] == #'b', cnt[1] == #'a', cnt[2] == #'l',
        // cnt[3] == #'o', cnt[4] == #'n'
        int ret;
        
        for(char ch: text) {
            switch(ch) {
                case 'b': cnt[0]++; break;
                case 'a': cnt[1]++; break;
                case 'l': cnt[2]++; break;
                case 'o': cnt[3]++; break;
                case 'n': cnt[4]++; break;
            }
        }
        cnt[2] /= 2; cnt[3] /= 2;
        ret = *min_element(cnt, cnt+5);
        return ret;
    }
};