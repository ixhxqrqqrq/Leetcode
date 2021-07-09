

bool canJump(int* nums, int numsSize){
    if(numsSize == 1) return true;
    int maxreach = nums[0];
    for(int i=0;i<numsSize-1 && i<=maxreach;i++){
        maxreach = maxreach>(i + nums[i])?maxreach:(i + nums[i]);
        if(maxreach>=numsSize-1) return true;
    }
    return false;

}
