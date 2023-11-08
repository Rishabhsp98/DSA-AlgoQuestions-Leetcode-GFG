class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xdiff = abs(fx-sx);
        int ydiff = abs(fy-sy);
        
        
        
        if(xdiff == 0 && ydiff == 0 && t == 1)
            return false;
        
        
        // first we move diagonal then horizontal / vertical
        int timeElapsed = min(xdiff,ydiff) + abs(xdiff - ydiff); // this is nothing but max(xdiff,ydiff)
        
        return timeElapsed <=t;
    }
};