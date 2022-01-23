class Solution {
public:
    vector<int> seqStrings(int n) {
        // 2 <= n <= 9
        vector<int> ans;
        string seq = "";
        
        // seq = "12...n"
        for(char ch = '1'; ch <= n+'0'; ch++) {
            seq.push_back(ch);
        }
        
        while(seq.back() <= '9') {
            ans.push_back(stoi(seq));
            seq = seq.substr(1);
            seq.push_back(seq.back()+1);
        }
        
        return ans;
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string l = to_string(low), h = to_string(high);
        for(int n = l.size(); n <= h.size(); n++) {
            vector<int> container = seqStrings(n);
            for(int& num: container) {
                if(low <= num and num <= high)
                    ans.push_back(num);
            }
        }
        
        return ans;
    }
};