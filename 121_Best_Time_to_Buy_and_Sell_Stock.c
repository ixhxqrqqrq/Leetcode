int maxProfit(int* prices, int pricesSize){
    int buyprices = prices[0];
    int maxprofit = 0;
    for ( int i = 0; i < pricesSize; i++ ) {
        if(prices[i]<buyprices) buyprices = prices[i];
        else if(prices[i]-buyprices > maxprofit) maxprofit = prices[i]-buyprices;
    }
    return maxprofit;
}
