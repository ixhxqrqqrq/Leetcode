/*
 * =====================================================================================
 *
 *       Filename:  fnBubble_Sort.c
 *
 *    Description:  BubbleSort
 *
 *        Version:  1.0
 *        Created:  03/22/2021 03:21:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  TSENG,CHIA-CHING (punja), punja@gmail.com
 *   Organization:  NTU
 *
 * =====================================================================================
 */

void BubbleSort(int* nums,int numsSize){
  for(int i = 0;i<numsSize-1;i++){
    for(int j=0;j<numsSize-i-1;j++){
      if(nums[j]>nums[j+1]){
        int temp = nums[j];
        nums[j] = nums[j+1];
        nums[j+1] = temp;
      }
    }
  }
}
