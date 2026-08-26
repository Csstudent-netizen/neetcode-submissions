class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_multiset<char> ana;
        for(int i=0; i<s.size(); ++i) {
            ana.insert(s[i]);
        }
        for(int i=0; i<t.size(); ++i) {
            auto temp = ana.find(t[i]);
            if(temp != ana.end()) ana.erase(temp);
            else return false;
            
        }
        if(ana.size() == 0) return true;
        return false;
    }
};
