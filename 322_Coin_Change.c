 int MIN(const int a, const int b){
    return a<b?a:b;
}
int coinChange(int* coins, int coinsSize, int amount){
    if(amount == 0) return 0;
    int min = INT_MAX;
    int* dp = (int*)calloc(amount+1,sizeof(int));
    dp[0] = 0;
    for(int i=1;i<=amount;i++){
        dp[i] = amount+1;
    }

    for(int i = 1;i<=amount;i++){
        for(int j=0;j<coinsSize;j++){
            if(i<coins[j]) continue;
            dp[i] = MIN(dp[i-coins[j]]+1,dp[i]);
        }
    }

    return dp[amount]==amount+1?-1:dp[amount];
}
