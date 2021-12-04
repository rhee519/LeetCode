class Trie {
public:
    unordered_map<char, Trie*> children;
    // Trie* children[26] = {nullptr, };
    bool last = false;
    void insert_reverse(string& word) {
        Trie* curr = this;
        for(int i = word.size()-1; i >= 0; i--) {
            if(!curr->children[word[i]]) 
                curr->children[word[i]] = new Trie();
            curr = curr->children[word[i]];
        }
        curr->last = true;
    }
    bool search(string &word) {
        Trie* curr = this;
        for(int i = word.size()-1; i >= 0; i--) {
            if(curr->children[word[i]]) {
                curr = curr->children[word[i]];
                if(curr->last) return true;
            } else break;
        }
        return false;
    }
};

class StreamChecker {
public:
    Trie* t;
    string stream = "";
    StreamChecker(vector<string>& words) {
        t = new Trie();
        for(string& word: words) {
            t->insert_reverse(word);
        }
    }
    
    bool query(char letter) {
        stream += letter;
        return t->search(stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */