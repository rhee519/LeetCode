class CombinationIterator {
public:
    string str;
    int len, clen, last, iter;
    
    CombinationIterator(string characters, int combinationLength) {
        // sort(characters.begin(), characters.end());
        str = characters; len = str.size(); clen = combinationLength;
        iter = (1<<len)-1;
        last = iter>>(len-clen);
        // print(last, len);
    }
    
    bool match(int mask, int len, int clen) {
        for(int flag = 1; flag < 1<<len; flag <<= 1) {
            if(mask&flag) clen--;
            if(clen < 0) return false;
        }
        return clen == 0;
    }
    
    string next() {
        string s = "";
        while(!match(iter, len, clen)) iter--;
        // print(iter, len);
        for(int i = 0, flag = 1<<(len-1); i < len; i++) {
            if(iter&flag) s += str[i];
            flag >>= 1;
        }
        iter--;
        return s;
    }
    
    bool hasNext() {
        return iter > last;
    }
    
    void print(int mask, int len) {
        for(int flag = 1<<(len-1); flag; flag >>= 1) {
            int bit = (mask&flag)? 1 : 0;
            cout << bit;
        } cout << "\n";
    }
};


/*
1 010 011 100 101 110 111 1000 1001 1010 1011 1100 1101 1110 1111
*/
/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */