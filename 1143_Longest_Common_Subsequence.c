
int max(int a, int b){
    return a>b?a:b;
}
int lcs(char* text1, char* text2, int m, int n, int** cache){
    int res;
    if(m<0||n<0) return 0;
    if(cache[m][n] != -1) return cache[m][n];
    if(text1[m] == text2[n]){
        res = lcs(text1,text2,m-1,n-1, cache)+1;
    }
    else{
        res = max(lcs(text1,text2,m-1,n,cache),lcs(text1,text2,m,n-1,cache));
    }
    cache[m][n] = res;
    return res;
}
int longestCommonSubsequence(char * text1, char * text2){
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    int res = 0;
    int** cache = malloc((len1+1)*sizeof(int*));
    for(int i=0;i<=len1;i++){
        cache[i] = malloc((len2+1)*sizeof(int));
    }
    for(int i=0;i<=len1;i++){
        for ( int j=0; j<=len2; j++ ) {
            cache[i][j] = -1;
        }
    }
    res = lcs(text1,text2,len1-1,len2-1,cache);
    return res;
}
/* TLE */
/*
int max(int a, int b){
    return a>b?a:b;
}
int lcs(char* text1, char* text, int m, int n){
    if(m<0||n<0) return 0;
    if(text1[m] == text2[n]){
        return lcs(text1,text2,m-1,n-1)+1;
    }
    else{
       return  max(lcs(text1,text2,m-1,n),lcs(text1,tex2,m,n-1));
    }
    return 0;
}
int longestCommonSubsequence(char * text1, char * text2){
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    int res = 0;
    lcs(text1,text2,len1-1,len2-1);
    return res;
}
*//
