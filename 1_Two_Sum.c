
/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Data{
    int num;
    int index;
};
int cmp(const void** a,const void** b){
    struct Data* A = (struct Data*)*a;
    struct Data* B = (struct Data*)*b;
    return A->num - B->num;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i=0,j=numsSize-1;
    *returnSize = 2;
    int* res = malloc(sizeof(int)*2);
    struct Data** data = (struct Data**)malloc(numsSize*sizeof(struct Data*));
    for(int i=0;i<numsSize;i++){
        data[i] = (struct Data*)malloc(sizeof(struct Data));
        data[i]->index = i;
        data[i]->num = nums[i];
    }
    qsort(data,numsSize,sizeof(struct Data),cmp);

    
    for(int i=0;i<numsSize;i++){
        printf("%d ",data[i]->num);
    }
    while(j>i){
        int sum = data[i]->num + data[j]->num;
        if(sum<target) i++;
        else if(sum>target) j--;
        else{
            res[0] = data[i]->index;
            res[1] = data[j]->index;
            break;
        }
    }
    return res;
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

# define SIZE 20
struct HashItem{
    int data;
    int key;
    struct HashItem* next;
};
int hashCode(int data){
    data = data>0?data:-data;
    return data % SIZE;
}
void insert(struct HashItem* HashArray[],int data,int key){
    struct HashItem *item = (struct HashItem*)malloc(sizeof(struct HashItem));
    item->data = data;
    item->key = key;
    item->next = NULL;

    //get the hash
    int hashIndex = hashCode(data);
    
    //move to array until an empty 
    if(HashArray[hashIndex]==NULL){
        HashArray[hashIndex] = item;
    }
    else{
        struct HashItem* temp = HashArray[hashIndex];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = item;
    }
}
struct HashItem* search(struct HashItem* HashArray[],int data){
    //get the hash
    int hashIndex = hashCode(data);

    if(HashArray[hashIndex]==NULL) return NULL;
    else{
        struct HashItem* temp = HashArray[hashIndex];
        while(temp!= NULL){
            if(temp->data == data) return temp;
            else {
               temp = temp->next; 
            }
        }
    }
    return NULL;
} 
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* res = (int*)malloc(2 * sizeof(int));
    struct HashItem* HashArray[SIZE];
    memset(HashArray,0,SIZE*sizeof(struct HashItem*));

    for(int i = 0;i<numsSize;i++){
        int find = target - nums[i];
        struct HashItem* temp = search(HashArray,find);
        if(!temp) insert(HashArray,nums[i],i);
        else{
            res[0] = i;
            res[1] = temp->key;  
        }
    }
    return res;
}
