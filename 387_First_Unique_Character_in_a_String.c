int firstUniqChar(char * s){
    int map[128]={0};
    int map2[128]={0};
    int res=-1;
    for(int i = 0;s[i]!='\0';i++){
        map[s[i]]++;
        map2[s[i]]=i;
    }
    for(int i = 0;s[i]!='\0';i++){
        if(map[s[i]] == 1) return res=map2[s[i]];

    }
    return res;
}
