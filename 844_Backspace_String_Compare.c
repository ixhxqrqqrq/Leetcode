void backspace(char *s){
    int j=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i] == '#'){
            j--;
            if(j<0) j=0;
        } 
        else{
            s[j]=s[i];
            j++;
        }
    }
    s[j] = '\0';
}

bool backspaceCompare(char * s, char * t){
    backspace(s);
    backspace(t);
    return !strcmp(s,t);
}
