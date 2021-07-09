/*
 * =====================================================================================
 *
 *       Filename:  fnQuick_Sort.c
 *
 *    Description: QuickSort 
 *
 *        Version:  1.0
 *        Created:  03/22/2021 03:39:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  TSENG,CHIA-CHING (punja), punja@gmail.com
 *   Organization:  NTU
 *
 * =====================================================================================
 */

void fnQuick_Sort(int* nums,int low,int high){
    int K, i,j, temp;
    if(low < high){
        K = low;
        i = low;
        j = high;
        while(i < j){
            while(nums[i] <= nums[K] && i <= high){
                i++;
            }
            while(nums[j] > nums[K] && j >= low){
                j--;
            }
            if(i < j){
               temp = nums[i];
               nums[i] = nums[j];
               nums[j] = temp; 
            }
        }
        //i>j => j K swap
        temp = nums[j];
        nums[j] = nums[K];
        nums[K] = temp;
        fnQuick_Sort(nums, low, j-1);
        fnQuick_Sort(nums,j+1,high);
    }
}

// Geeksforgeeks

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 
 
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
