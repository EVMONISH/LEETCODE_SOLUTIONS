class Solution {
public:
    int mySqrt(int x) {
        int start = 1, end = x/2;
        int res = 0;
        if(x<2) return x;
        while(start <= end)
        {
            int mid = (start+end)/2;

            if((long long) mid * mid <= x)
            {
                res = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return res;
    }
};