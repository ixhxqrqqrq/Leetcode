int sqortsum(int n){
    int res = 0;
    while(n!=0){
        int a = n%10;
        n /=10;
        res += a*a;
    }
    return res;
}

bool isHappy(int n){
    int slow,fast;
    slow = sqortsum(n);
    fast = sqortsum(sqortsum(n));
    while(slow != fast){
        slow = sqortsum(slow);
        fast = sqortsum(sqortsum(fast));
    }
    return slow==1;
}
