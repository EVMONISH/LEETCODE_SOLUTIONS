class Solution {
public:
    bool isPowerOfThree(int n) {

        if(n<0)
            return false;
        
        int ans = 1;

        for(int i=0; i<=30; i++)
        {
            if(ans == n) 
            {
                return true;
            }
            
            if(ans > INT_MAX / 3) break;
            ans*=3;
        }
        return false;
    }
};