int extractMax(int* stones, int stonesSize){
    int index = 0;
    int max = stones[0];
    for ( int i=0; i<stonesSize; i++ ) {
        if ( stones[i]>max ) {
            max = stones[i];
            index = i;
        }
    }
    stones[index]=0;
    return max;    

}
void insert(int* stones, int stonesSize,int weight){
    
    for ( int i=0; i<stonesSize; i++ ) {
        if(stones[i]==0) {
            stones[i] = weight;
            break;
        }
    }
}
int lastStoneWeight(int* stones, int stonesSize){
    int stone1 = extractMax(stones, stonesSize);
    int stone2 = extractMax(stones, stonesSize);
    int weight = 0;
    while ( stone1!=0 && stone2 !=0  ) {
        weight = stone1-stone2;
        insert(stones, stonesSize, weight);
        stone1 = extractMax(stones, stonesSize);
        stone2 = extractMax(stones, stonesSize);
    }
    return stone1;
}
