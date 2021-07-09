int maxSubArray(int* nums, int numsSize){
    int maxsum = nums[0];
    int sum = 0;
    for ( int i=0; i<numsSize; i++ ) {
        sum += nums[i];
        if(nums[i] > sum) sum = nums[i];
        if(sum > maxsum) maxsum = sum;         
    }
    return maxsum;
}

int maxSubArray(int* nums, int numsSize){
    int maxsum = nums[0];
    int sum = 0;
    for(int i = 0;i<numsSize;i++){
        sum += nums[i];
        if(maxsum < sum) maxsum = sum;
        if(sum < 0) sum = 0;
    }
    return maxsum;    
}

