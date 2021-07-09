int maxProfit(int* prices, int pricesSize){
    int buyprices = prices[0], sellprices = prices[0], profit = 0;
    for(int i=1;i<pricesSize;i++){
        if(prices[i]<buyprices) buyprices = prices[i];
        else{
            profit += prices[i] - buyprices;
            buyprices = prices[i];            
        }
    }
    return profit;
}
