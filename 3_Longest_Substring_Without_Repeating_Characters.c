int lengthOfLongestSubstring(char * s){
    int left=0,len=0,maxlen=0;
    int map[257] = {0};
    for(int i=0;s[i]!='\0';i++){
        if(map[s[i]]==0) {
            map[s[i]] = i+1;
            len=i + 1 - left;
            maxlen = maxlen>len?maxlen:len;
        }
        else{
            int temp = left>map[s[i]]?left:map[s[i]];
            len = i + 1 - temp;
            left = left>map[s[i]]?left:map[s[i]];
            map[s[i]] = i + 1;
            maxlen = maxlen>len?maxlen:len;            
        }
        printf("%d ",len);
    }
    return maxlen;
}
