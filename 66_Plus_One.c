/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int addone = 1;
    *returnSize = digitsSize;
    for(int i=digitsSize-1;i>=0&&addone == 1;i--){
        int temp = digits[i] + addone;
        addone = temp / 10;
        if(addone) temp %= 10;
        digits[i] = temp;
    }
    if(addone == 1){
        int* res = (int*)malloc(sizeof(int)*(digitsSize+1));
        res[0]=1;
        for(int i = 0;i<digitsSize;i++){
            res[i+1] = digits[i];
        }
        (*returnSize)++;
        return res;
    }
    return digits;
}
