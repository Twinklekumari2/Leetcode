class Solution {
public:
    int dp[1001][1501];
    int cheapestPrice = INT_MAX;
    int solve(int n, vector<vector<int>>& items, int budget, vector<int>& copies){
        if(n == 0){
            return budget/cheapestPrice;
        }
        if(dp[n-1][budget] != -1){
            return dp[n-1][budget];
        }
        int take = 0, skip = 0;
        if(items[n-1][1] <= budget){
            take = 1 + copies[n-1] + solve(n-1, items, (budget - items[n-1][1]), copies);
        }
        skip = solve(n-1, items, budget, copies);
        return dp[n-1][budget] = max(skip, take);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> copies(n);
        for(int i = 0; i < n; i++){
            int count = 0;
            cheapestPrice = min(cheapestPrice, items[i][1]);
            for(int j = 0; j < n; j++){
                if(j != i && (items[j][0] % items[i][0]) == 0){
                    count++;
                }
            }
            copies[i] = count;
        }

        memset(dp,-1, sizeof(dp));
        return solve(n, items, budget, copies);
    }
};