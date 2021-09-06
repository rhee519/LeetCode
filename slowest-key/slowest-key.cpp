class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char slowestKey = keysPressed[0];
        int maxDuration = releaseTimes[0];
        int n = keysPressed.length();
        
        for(int i = 1; i < n; i++) {
            int duration = releaseTimes[i] - releaseTimes[i-1];
            if(maxDuration < duration) {
                maxDuration = duration;
                slowestKey = keysPressed[i];
            } else if(maxDuration == duration) {
                slowestKey = max(slowestKey, keysPressed[i]);
            }
        }
        
        return slowestKey;
    }
};