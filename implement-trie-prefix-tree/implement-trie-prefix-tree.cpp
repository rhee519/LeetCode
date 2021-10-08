class Trie {
    Trie* children[26] = {nullptr, };
    bool exist = false;
public:
    Trie() { }
    
    void insert(string word) {
        Trie* curr = this;
        int len = word.size();
        for(int i = 0; i < len; i++) {
            if(!curr->children[word[i]-'a']) 
                curr->children[word[i]-'a'] = new Trie();
            curr = curr->children[word[i]-'a'];
        }
        curr->exist = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        int len = word.size();
        for(int i = 0; i < len; i++) {
            if(!curr->children[word[i]-'a']) {
                return false;
            }
            curr = curr->children[word[i]-'a'];
        }

        return curr->exist == true;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        int len = prefix.size();
        for(int i = 0; i < len; i++) {
            if(!curr->children[prefix[i]-'a']) {
                return false;
            }
            curr = curr->children[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */