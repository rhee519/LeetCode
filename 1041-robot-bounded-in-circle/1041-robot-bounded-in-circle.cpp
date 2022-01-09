class Solution {
public:
    // clockwise: ++, counter-clockwise: --
    int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, 1, 0, -1};
    
    bool isRobotBounded(string instructions) {
        int y = 0, x = 0;
        int direction = 0;
        for(char inst: instructions) {
            if(inst == 'G') {
                y += dy[direction];
                x += dx[direction];
            } else if(inst == 'L') {
                direction += 3; // -1 % 4 == -1 so +3 instead of --
                direction %= 4;
            } else if(inst == 'R') {
                direction++;
                direction %= 4;
            }
        }
        
        return (y == 0 and x == 0) or direction;
    }
};