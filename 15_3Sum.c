/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int** threeSum(int* nums,int numsSize,int* returnSize,int** returnColumnSizes){
    *returnSize=0;
    if(numsSize==0||numsSize==1||numsSize==2){
        return NULL;
    }
    int **ret=malloc(sizeof(int *)*100000);
    *returnColumnSizes=malloc(sizeof(int)*100000);
    int left=0,right=numsSize-1,target=0;
    ret[*returnSize]=malloc(sizeof(int)*3);
    qsort(nums,numsSize,sizeof(int),cmp);
    while(left+1<right){
        int i=left+1,j=right,target=0-nums[left];
        while(i<j){
            if(nums[i]+nums[j]<target){
                i++;
            }
            else if(nums[i]+nums[j]>target){
                j--;
            }
            else{
                ret[*returnSize][0]=nums[left];
                ret[*returnSize][1]=nums[i];
                ret[*returnSize][2]=nums[j];
                (*returnColumnSizes)[*returnSize]=3;//跟37行同義
                (*returnSize)++;
                ret[*returnSize]=malloc(sizeof(int)*3);
                while(i<j&&nums[i]==nums[++i]){}
                while(i<j&&nums[j]==nums[--j]){}
            }
        }
        while(left+1<right&&nums[left]==nums[++left]){}
    }
    return ret;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/*
int cmp(void* a, void* b){
    return *(int*)a - *(int*)b;
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums,numsSize,sizeof(int),cmp);
    int i=0, left = 1, right = numsSize-1;
    *returnSize = 0;
    int** res = (int**)malloc(1*sizeof(int*));
    *returnColumnSizes = malloc(sizeof(int));
    
    
    for(;i<numsSize-2;i++){
        left = i+1;
        right = numsSize-1;
        int target = (-1) * (nums[i]);
        while(left<right){
            if (left > i + 1 && nums[left - 1] == nums[left]) {
                left++;
                continue;
            }
            
            if(nums[left]+nums[right] < target){
                left++;
            }
            else if(nums[left]+nums[right] > target){                
                right--;
            }
            else{
                //printf("%d+%d+%d = 0\n",nums[i],nums[left],nums[right]);
                (*returnSize)++;
                res = realloc(res,sizeof(int*)*(*returnSize));
                *returnColumnSizes = realloc(*returnColumnSizes,sizeof(int)*(*returnSize));
                res[*returnSize-1] = malloc(sizeof(int)*3);

                res[*returnSize-1][0] = nums[i];
                res[*returnSize-1][1] = nums[left];
                res[*returnSize-1][2] = nums[right];
                (*returnColumnSizes)[*returnSize-1] = 3; 
                left++;
                right--;
            }
        }
    }
    return res;

}
*/
