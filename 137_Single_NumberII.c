int singleNumber(int* nums, int numsSize){
    int one = 0, two = 0, three = 0;
    for(int i=0;i<numsSize;i++){
        two |= one&nums[i];
        one = one^nums[i];
        three = one&two;
        one = one&(~three);
        two = two&(~three);
    }
    return one;

}
