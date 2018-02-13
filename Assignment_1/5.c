#include<stdio.h>

long long int power(int n){
    long long int ans,tmp;
    int i=1;
    if(n==0) return 1;
    tmp = ans = 2*power(n-1);
    while(i>0){
        if(tmp/(10000000000*i)!=0){
            i++;
        }
        else{
            i--;
            break;
        }
    }
    ans = ans - (10000000000*i);
    return ans;
}
int five(){

    int n;
    scanf("%d",&n);
    printf("%lld",power(n));
    return 0;
}
