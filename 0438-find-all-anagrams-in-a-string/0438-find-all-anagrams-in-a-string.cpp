class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<int> ans;
        if(m>n) return ans;

        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(int i=0; i<m; i++)
        {
            freq1[p[i] - 'a']++;
        }

        int left = 0;

        for(int right = 0; right<n; right++)
        {
            freq2[s[right] - 'a']++;

            if(right-left+1 > m)
            {
                freq2[s[left] - 'a']--;
                left++;
            }

            if(right-left+1  == m)
            {
                if(freq1 == freq2)
                {
                    ans.push_back(left);
                }
            }
        }
        return ans;
    }
};