class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> bestbuy(prices.size()); //best buy price
        bestbuy[0]=prices[0];
        for(int i=1;i<prices.size();i++){
            bestbuy[i]=min(prices[i-1],bestbuy[i-1]);
        }
        int maxprofit=0;
        for(int i=1;i<prices.size();i++){//profit =sell-buy
           int profit=prices[i]-bestbuy[i];
           maxprofit=max(profit,maxprofit);
        }
        return maxprofit;

    }
};
