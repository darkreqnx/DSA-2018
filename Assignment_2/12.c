#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

    int n,x;
    scanf("%d %d",&n,&x);
    int flag=0,a,i,count=0;
    for(i=0;i<n;i++){
        scanf("%d",&a);
        if(a==x){
            count++;
            flag=1;
        }
        if(flag==1 && a!=x) break;
    }
    printf("%d",count);


    return 0;
}

