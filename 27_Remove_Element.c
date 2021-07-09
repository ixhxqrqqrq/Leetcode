int removeElement(int* nums, int numsSize, int val){
    int slow=0;
    for (int i=0 ;i<numsSize ; i++){
        if(nums[i] != val){
            nums[slow] = nums[i];
            slow++;
        }
    }
    return slow;
}
