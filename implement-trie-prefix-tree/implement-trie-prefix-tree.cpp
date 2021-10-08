class Trie {
    unordered_map<char, Trie*> children;
    bool exist = false;
public:
    Trie() { }
    
    void insert(string word) {
        int len = word.size();
        Trie* curr = this;
        for(int i = 0; i < len; i++) {
            if(!(curr->children.count(word[i]))) 
                curr->children[word[i]] = new Trie();
            curr = curr->children[word[i]];
        }
        curr->exist = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        int len = word.size();
        for(int i = 0; i < len; i++) {
            if(!(curr->children.count(word[i]))) {
                // printf("word[%d] doesn't exist\n", i);
                return false;
            }
            curr = curr->children[word[i]];
        }

        return curr->exist == true;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        int len = prefix.size();
        for(int i = 0; i < len; i++) {
            if(!(curr->children.count(prefix[i]))) {
                // printf("prefix[%d] doesn't exist\n", i);
                return false;
            }
            curr = curr->children[prefix[i]];
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