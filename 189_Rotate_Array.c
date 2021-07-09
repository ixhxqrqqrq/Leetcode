void rotate(int* nums, int numsSize, int k){
    k %= numsSize;
    int* temp = (int*)malloc(sizeof(int)*k);
    for(int i=0;i<k;i++){
        temp[k-1-i] = nums[numsSize-1-i];
    }
    for(int i=0;i<numsSize-k;i++){
        nums[numsSize-1-i] = nums[numsSize-1-i-k];
    }
    for(int i=0;i<k;i++){
        nums[i] = temp[i];
    }
}
