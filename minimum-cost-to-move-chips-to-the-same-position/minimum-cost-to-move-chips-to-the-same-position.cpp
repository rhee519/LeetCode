class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0;
        for(int pos: position) {
            if(pos%2 == 0) even++;
        }
        return min(even, (int)position.size()-even);
    }
};