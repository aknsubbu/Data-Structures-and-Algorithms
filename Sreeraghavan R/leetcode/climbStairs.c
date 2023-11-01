int climbStairs(int n){
    if(n <= 1){
        return 1;
    }
    return climbStairs(n-1)+climbStairs(n-2);
}

int main(){
    int n =41;
    int result = climbStairs(n);
    printf("%d", result);
    return 0;
}