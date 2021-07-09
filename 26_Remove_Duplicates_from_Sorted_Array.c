int removeDuplicates(int* nums, int numsSize){
    if(numsSize == 0) return 0;
    else if(numsSize == 1) return 1;
    else{
        int i=1,j=1;
        int oldnum = nums[0];
        for(i=1;i<numsSize;i++){
            if(nums[i]!=oldnum){ 
                nums[j] = nums[i];
                j++;
                oldnum = nums[i];
            }
        }
    return j;
    }
    
}
