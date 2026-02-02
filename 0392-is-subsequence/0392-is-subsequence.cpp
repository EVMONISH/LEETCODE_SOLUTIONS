class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0;
        int n = t.length();
        while(i<n)
        {
            if(t[i] == s[j])
            {
                j++;
            }
            i++;
        }
        return j==s.length();
    }
};