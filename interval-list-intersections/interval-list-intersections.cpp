class Solution {
public:
    vector<int> getIntersection(vector<int>& first, vector<int>& second) {
        vector<int> ret;
        int start = max(first[0], second[0]), finish = min(first[1], second[1]);
        if(start <= finish) {
            ret.push_back(start);
            ret.push_back(finish);
        }
        return ret;
    }
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int m = 0, n = 0;
        while(m < firstList.size() and n < secondList.size()) {
            vector<int> intersection = getIntersection(firstList[m], secondList[n]);
            if(!intersection.empty()) ans.push_back(intersection);
            if(firstList[m][1] < secondList[n][1]) m++;
            else if(firstList[m][1] > secondList[n][1]) n++;
            else {
                m++; n++;
            }
        }
        
        return ans;
    }
};