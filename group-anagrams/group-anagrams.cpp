class Solution {
public:
    struct myComp {
        bool operator() (const string& str1, const string& str2) const {
            // M == str1.length, N == str2.length
            // Time complexity: O(M+N)
            int abc[26] = {0, };
            if(str1.length() != str2.length()) {
                return str1.length() < str2.length();
            }
            
            // str1.length == str2.length
            for(auto ch: str1) {
                abc[ch-'a']++;
            }
            for(auto ch: str2) {
                abc[ch-'a']--;
            }
            for(auto cnt: abc) {
                if(cnt) return cnt > 0;
            }

            // str1 & str2 is anagram
            return false;
        }
    };
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>, myComp> myMap;
        // key   == representative of anagram group
        // value == string
        
        for(auto str: strs) {
            myMap[str].push_back(str);
        }
        
        for(auto it: myMap) {
            // it.first  == key     (string)
            // it.second == value   (vector<string>)
            ans.push_back(it.second);
        }
        
        return ans;
    }
};