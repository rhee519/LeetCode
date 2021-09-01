class Solution {
public:
    struct myComp {
        bool operator()(const int& a, const int& b) const {
            if(abs(a) == abs(b)) return a < b;
            return abs(a) < abs(b);
        }
    };
    
    
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int, myComp> myMap;
        // myMap == {key: count}
        int size = arr.size();
        
        // push to map
        for(int i = 0; i < size; i++) {
            myMap[arr[i]]++;
        }
        
        // process key 0
        if(myMap[0] % 2) return false;
        myMap.erase(0);
            
        // make double pairs
        for(auto it = myMap.begin(); it != myMap.end(); ) {
            // ip == pointer of pair key
            auto ip = myMap.find(2 * it->first);
            if(ip == myMap.end() || ip->second < it->second) return false;
            ip->second -= it->second;
            if(ip->second == 0) myMap.erase(ip);
            myMap.erase(it++);
        }
        
        return true;
    }
};