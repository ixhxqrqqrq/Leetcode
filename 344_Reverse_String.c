
void swap(char* a,char* b){
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}
void reverseString(char* s, int sSize){
    int times = sSize/2;
    for(int i=0;i < times;i++){
       swap(&s[i],&s[sSize-1-i]); 
    }

}
 
