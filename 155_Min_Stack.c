/*----------------------------------------------------------- */
typedef struct {
    int *data;
    int *mindata;
    int size;    
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->data = (int*)malloc(sizeof(int));
    obj->mindata = (int*)malloc(sizeof(int));
    obj->mindata[0] = INT_MAX;
    obj->size = 0;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    int min;
    if(obj->size == 0) min = INT_MAX;
    else min = obj->mindata[obj->size-1];
    
    obj->size++;
    
    obj->data = realloc(obj->data,sizeof(int)*obj->size);
    obj->mindata = realloc(obj->mindata,sizeof(int)*obj->size);
    
    obj->data[obj->size-1] = val;
    obj->mindata[obj->size-1] = val<min?val:min;

}

void minStackPop(MinStack* obj) {
    obj->size--;  
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->size-1];
}

int minStackGetMin(MinStack* obj) {
    return obj->mindata[obj->size-1];  
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->mindata);
    free(obj);
    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
