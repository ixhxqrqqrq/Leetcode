/*  
    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    */
/*  
1. If the current value is greater than or equal to the value of
the symbol to the right, add the current symbol’s value to the total.
2. If the current value is smaller than the value of the symbol to
the right, subtract the current symbol’s value from the total.
*/
int reman(char s){
    if(s=='I') return 1;
    else if(s == 'V') return 5;
    else if(s == 'X') return 10;
    else if(s == 'L') return 50;
    else if(s == 'C') return 100;
    else if(s == 'D') return 500;
    else if(s == 'M') return 1000;
    return 0;
}
int romanToInt(char * s){
    int res = 0;
    for (int i=0 ;s[i]!='\0' ;i++ ){
        if(reman(s[i]) >= reman(s[i+1])){
            res += reman(s[i]);
        }
        else{
            res -= reman(s[i]);    
        }
    }
    return res;
}
