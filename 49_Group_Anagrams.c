//incompleted

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


//structure of each word of dulplicate array
struct Word{
    char* str;  // to store word itself
    int index;  // index of the word in the original array
};

//structure to represent duplicate array
struct DupArray{
    struct Word* array;  //Array of words
    int size;    
};

struct DupArray* creatDupArray(char** str, int size){
    struct DupArray* dupArray = (struct DupArray*)malloc(sizeof(struct DupArray));
    dupArray->size = size;
    dupArray->array = (struct Word*)malloc(dupArray->size * sizeof(struct Word));
    int i;
    for(i=0;i<size;i++){
        dupArray->array[i].index = i;
        dupArray->array[i].str = (char*)malloc(strlen(str[i])+1);
        strcpy(dupArray->array[i].str,str[i]);
    }
    return dupArray;
}
// Compare two characters. Used in qsort() for sorting an array of 
// characters (Word)
int compChar(const void* a, const void* b){
    return *(char*)a-*(char*)b;
}
// Compare two words. Used in qsort() for sorting an array of words
int compStr(const void* a, const void* b){
    struct Word* a1 = (struct Word*)a;
    struct Word* b1 = (struct Word*)b;
    return strcmp(a1->str,b1->str);
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    struct DupArray* dupArray = creatDupArray(strs, strsSize);
    int i;
    for(i=0;i<strsSize;i++){
        qsort(dupArray->array[i].str, strlen(dupArray->array[i].str), sizeof(char), compChar);
    }
    qsort(dupArray->array, strsSize, sizeof(dupArray->array[0]), compStr);
    for(i=0;i<strsSize;i++){
        printf("%s\n",strs[dupArray->array[i].index]);
    }
    return dupArray;
}
