class Solution {
public:
    unordered_map<string, string> root, name;
    string find(string& email) {
        if(!root.count(email)) return root[email] = email;
        if(email == root[email]) return email;
        return root[email] = find(root[email]);
    }
    void merge(string& e1, string& e2) {
        root[find(e2)] = root[find(e1)];
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        for(auto& account: accounts) {
            for(int i = 1; i < account.size(); i++) {
                merge(account[1], account[i]);
                name[account[i]] = account[0];
            }
        }
        
        unordered_map<string, vector<string>> list;
        for(auto& p: root) {
            string key = p.first, parent = find(key);
            list[parent].push_back(key);
        }
        for(auto& l: list) {
            l.second.push_back(name[l.first]);
            swap(l.second.front(), l.second.back());
            sort(l.second.begin()+1, l.second.end());
            ans.push_back(l.second);
        }
        
        return ans;
    }
};