int searchInsert(int* nums, int numsSize, int target){
    int i = 0;
    if(nums[0]>=target) return 0;
    for (; i<numsSize && nums[i]<target; i++ );
    return i;
}
