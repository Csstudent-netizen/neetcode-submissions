class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1, r = *max_element(piles.begin(), piles.end());
        int m;
        int mini = r;
        if(h == piles.size()) return r;
        while(l<=r){
            m = l + (r-l)/2;
            long long tot_hr = 0;
            for(int i=0;i<piles.size();++i)tot_hr+=(piles[i]+m-1)/m;
            if(tot_hr <= h){
                mini = m;
                r = m-1;
            }
            else l = m+1;
        }

        return mini;
    }
};
