/*
 * =====================================================================================
 *
 *       Filename:  fnSelection_Sort.c
 *
 *    Description: SelectionSort 
 *                  (Sorting data from left to right. Take the smallest data to index i each for loop)
 *        Version:  1.0
 *        Created:  03/22/2021 03:22:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  TSENG,CHIA-CHING (punja), punja@gmail.com
 *   Organization:  NTU
 *
 * =====================================================================================
 */


void fnSelection_Sort(int* nums,int numsSize){
    for(int i = 0;i < numsSize-1;i++){
        for(int j = i+1;j < numsSize;j++){
            if(nums[i] > nums[j]){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}
