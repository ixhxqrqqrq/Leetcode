bool isAnagram(char * s, char * t){
    int slen = strlen(s);
    int tlen = strlen(t);
    if(slen!=tlen) return false;
    else{
        int map[128]={0};
        for(int i=0;i<slen;i++){
            map[s[i]]++;
            map[t[i]]--;
        }
        for(int i=0;i<slen;i++){
            if(map[s[i]]!=0)return false;
        }
        return true;
    }
}
