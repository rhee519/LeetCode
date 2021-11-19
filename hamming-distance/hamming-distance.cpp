class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0;
        int ex = x xor y;
        for(unsigned int flag = 1; flag; flag <<= 1) {
            if(flag&ex) dist++;
        }
        return dist;
    }
};