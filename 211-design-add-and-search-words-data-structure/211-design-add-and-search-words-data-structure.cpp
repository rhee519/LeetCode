class WordDictionary {
    WordDictionary* children[26] = {nullptr, };
    // e.g. word: "bad"
    // wd.children['b'-'a']->children['a'-'a']->children['d'-'a']->last == true
    bool last = false;
public:
    WordDictionary() { }
    
    void addWord(string word) {
        WordDictionary* curr = this;
        for(char ch: word) {
            WordDictionary* &child = curr->children[ch-'a'];
            if(!child) child = new WordDictionary();
            curr = child;
        }
        curr->last = true;
    }
    
    bool search(string word) {
        WordDictionary* curr = this;
        return searchDFS(word, curr, 0);
    }
    
    bool searchDFS(string word, WordDictionary* curr, int idx) {
        if(!curr)
            return false;
        if(idx == word.size()) 
            return curr->last;
        
        char ch = word[idx];
        if(ch == '.') {
            for(char tar = 'a'; tar <= 'z'; tar++) {
                if(searchDFS(word, curr->children[tar-'a'], idx+1))
                    return true;
            }
        } else { // lowercase
            if(!curr->children[ch-'a']) 
                return false;
            else return searchDFS(word, curr->children[ch-'a'], idx+1);
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */