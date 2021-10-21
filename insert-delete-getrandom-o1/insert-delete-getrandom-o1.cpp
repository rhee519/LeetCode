class RandomizedSet {
private:
    unordered_map<int, int> m;
    vector<int> index; // index[m[val]] = val
    random_device rd;
    mt19937 gen;
public:
    RandomizedSet() {
        gen = mt19937(rd());
    }
    
    bool insert(int val) {
        if(m.count(val)) return false;
        index.push_back(val);
        m[val] = index.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!m.count(val)) return false;
        int last_val = index[index.size()-1], idx = m[val];
        swap(index[idx], index[index.size()-1]);
        index[idx] = last_val;
        m[last_val] = idx;
        index.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        if(m.empty()) return 0;
        uniform_int_distribution<int> dist(0, index.size()-1);
        int idx = dist(gen);
        return index[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */