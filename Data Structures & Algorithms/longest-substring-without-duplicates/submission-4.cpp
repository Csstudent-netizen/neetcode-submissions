class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1) return 1;
        if(s.size()==0) return 0;
        int l = 0, r;
        int len = 1;
        unordered_set<char> dup;

        dup.insert(s[l]);
        for(r=1; r<s.size(); ++r){
            while(dup.count(s[r]) && l!=r){
                dup.erase(s[l]);
                ++l;
            }
            dup.insert(s[r]);
            len = max(len, (int)dup.size());
        }

        return len;
    }
};
