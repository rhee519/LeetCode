/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n, mid = ((long long)left+right)/2;
        while(left < right) {
            int g = guess(mid);
            // printf("mid: %d, guess: %d\n", mid, g);
            if(g == 0) break;
            else if(g == -1) {
                right = mid;
            } else { // g == 1
                left = mid+1;
            }
            mid = ((long long)left+right)/2;
        }
        
        return mid;
    }
};