/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* partitionLabels(char * S, int* returnSize){
    *returnSize = 0;
    int* res = NULL;
    int slow = -1,fast = 0;
    int len = strlen(S);
    int map[128];
    for(int i=0;i<len;i++){
        map[S[i]] = i;
    }
    fast = map[S[0]];
    for(int i=0;i<len;i++){
        int temp = map[S[i]];
        if(temp > fast) fast = temp;
        if(fast == i){
            (*returnSize)++;
            res = (int*)realloc(res,(*returnSize)*sizeof(int));
            res[(*returnSize)-1] = fast-slow;
            slow=fast;
            fast = map[S[i+1]];
        }
        
    }
    return res;
}



    
