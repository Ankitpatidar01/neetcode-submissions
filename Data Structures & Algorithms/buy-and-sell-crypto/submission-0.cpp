class Solution {
public:
    int solve(int index , int buy , vector<int>& prices , int trans){

        if(trans == 0){
            return 0;
        }

        if(index >= prices.size()) return 0;

        if(!buy){
            int buyed = -prices[index] + solve(index + 1 , buy ^ 1 , prices , trans);
            int notBuy = solve(index + 1 , buy , prices , trans);

            return max(buyed , notBuy);
        }else{

            int sell = +prices[index] + solve(index + 1 , buy ^ 1 , prices , trans - 1);
            int notSell = solve(index + 1 , buy , prices , trans);

            return max(sell , notSell);

        }

        return 0;
    }
    int maxProfit(vector<int>& prices) {
        return solve(0 , 0 , prices , 1);
    }
};
