
/* strstr() algorithm 
 * KMP algorithm ( String Matching )
 * pattern par[]
 * lps[]
 * 
 ********************************************************
Examples of lps[] construction:
For the pattern “AAAA”, 
lps[] is [0, 1, 2, 3]

For the pattern “ABCDE”, 
lps[] is [0, 0, 0, 0, 0]

For the pattern “AABAACAABAA”, 
lps[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]

For the pattern “AAACAAAAAC”, 
lps[] is [0, 1, 2, 0, 1, 2, 3, 3, 3, 4] 

For the pattern “AAABAAA”, 
lps[] is [0, 1, 2, 0, 1, 2, 3]
 *********************************************************
 *
 *
 * */



void computeLPSArray(char* pat, int M, int *lps){
    int len = 0;

    lps[0] = 0;
    // the loop calculates lps[i] for i=1 to M-1
    int i = 1;
    while(i < M){
        if ( pat[i] == pat[len] ) {
            len++;
            lps[i] = len;
            i++;
        }
        else { // (par[i] != par[len])
           // This is tricky. Consider the example.
           // AAACAAAA and i = 7. The idea is similar
           // to search step.
            if ( len != 0 ) {
                len = lps[len -1];
                // Also note that we do not increment i here
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

}

int strStr(char * haystack, char * needle){
    if(needle[0] == '\0') return 0;
    int M = strlen(needle);
    int N = strlen(haystack);
    int lps[M];
    computeLPSArray(needle, M, lps);
    int i = 0;
    int j = 0;
    while(i < N){
        if(needle[j] == haystack[i]){
            i++;
            j++;
        }
        if ( j==M ) {
            return i-M;
            j = lps[j-1];
        }
        else if( i<N && needle[j] != haystack[i]){
            if(j!=0){
                j = lps[j-1];
            }
            else {
                i = i+1; 
            }
        }
    }
    return -1;
}

