class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min= prices[0];
        int p=0;
        for(int i=1; i<prices.size(); ++i){
            if(prices[i-1]<min) min=prices[i-1];
            int temp= prices[i]-min;
            if(temp>p) p=temp;

        }
        return p;
    }
};
