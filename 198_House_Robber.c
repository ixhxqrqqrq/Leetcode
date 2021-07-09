int max(int a,int b){
    return a>b?a:b;
}

int rob(int* nums, int numssize){
    
    // steal
    // money[i] = money[i-2] + money[i]
    // not steal
    // money[i] = money[i-1]
    int maxmoney = nums[0];
    if(numssize == 1) return nums[0];
    if(numssize == 2) return max(nums[0],nums[1]);
    int back1 = nums[0];
    int back2 = max(nums[0],nums[1]);
    for(int i = 2;i<numssize;i++){
        maxmoney = nums[i]+back1>back2?nums[i]+back1:back2;
        back1 = back2;
        back2 = maxmoney;        
    }
    return maxmoney;    
}
