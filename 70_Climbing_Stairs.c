int climbStairs(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    int res = 0;
    int back1 = 1;
    int back2 = 2;
    for ( int i=3; i<=n; i++ ) {
        res = back1 + back2;
        back1 = back2;
        back2 = res;
    }
    return res;
}

/*  Time Limit Exceeded 
    int climbStairs(int n){
    if ( n== 1 ) return 1;
    else if ( n==2 ) return 2;
    else return climbStairs(n-1)+climbStairs(n-2); 
    } */
