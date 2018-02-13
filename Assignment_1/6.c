#include<stdio.h>
#include<math.h>
#include<string.h>

int six(){

    int c,n,p;
    int ans=1;
    scanf("%d %d %d",&c,&n,&p);
    int i;
    for(i=0;i<n;i++){
        ans = (ans*c)%p;
    }

    printf("%d",ans);
    return 0;
}
