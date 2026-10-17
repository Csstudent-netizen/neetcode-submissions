class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int> winmap;
        unordered_map<char, int> tmap;
        int count = 0;
        for(int i=0; i<t.size(); ++i){
            tmap[t[i]]++;
            count++;
        }

        int l = 0, r =0; 
        int match = 0;
        int mindx = 0, minlen = 1e9;
        while(tmap[s[l]] == 0 && l<s.size()){++l; ++r;}
        for(; r<s.size(); ++r){
            winmap[s[r]]++;
            if(winmap[s[r]] <= tmap[s[r]]){
                match++;
                if(match == count){
                    if(r-l+1 < minlen){
                        mindx = l;
                        minlen = r-l+1;
                    }
                }
            }
            else if(tmap[s[r]] > 0){
                while(tmap[s[l]] >= 0){
                    if(tmap[s[l]] >= winmap[s[l]]) break;
                    winmap[s[l]]--;
                    l++;
                }

                if(match == count){
                    if(r-l+1 < minlen){
                        mindx = l;
                        minlen = r-l+1;
                    }
                }
            }

        }

        if(minlen == 1e9) return "";
        else return s.substr(mindx, minlen);
    }
};
