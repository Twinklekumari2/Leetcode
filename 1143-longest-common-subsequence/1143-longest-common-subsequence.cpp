class Solution {
public:
    int f(int ind1, int ind2, string s1,string s2,vector<vector<int>>& dp){
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(s1[ind1] == s2[ind2]){
            return dp[ind1][ind2] = 1 + f(ind1-1, ind2-1, s1, s2,dp);
        }
        return dp[ind1][ind2] = max(f(ind1-1, ind2, s1, s2,dp), f(ind1, ind2-1, s1, s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int ind1 = text1.size();
        int ind2 = text2.size();
        vector<vector<int>> dp(ind1+1, vector<int>(ind2+1, -1));
        for(int i = 0; i <= ind2; i++) dp[0][i] = 0;
        for(int i = 0; i <= ind1; i++) dp[i][0] = 0;  

        for(int i = 1; i <= ind1; i++){
            for(int j = 1; j <= ind2; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                 }
                 else  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[ind1][ind2];
    }
};