class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string, int> m;
        for(string e: emails) {
            int idx = e.find('@');
            string local = e.substr(0, idx);
            string domain = e.substr(idx+1);
            
            int pos = local.find('+');
            if(pos != string::npos) local = local.substr(0, pos);
            while((pos = local.find('.')) != string::npos) {
                local.erase(pos, 1);
            }
            
            m[local + "@" + domain]++;
        }
        
        return m.size();
    }
};