#include <stdio.h>
#include <stdlib.h>

int eight()
{
    int m,n;
    int i;
    scanf("%d %d",&m,&n);
    int input[n];
    for(i=0;i<n;i++){
        scanf("%d",&input[i]);
    }
    for(i=0;i<n;i++){
        if(i<m){
            printf("-1 ");
            continue;
        }
        if(m%2==0){
            if(3*(input[(2i-m-1)/2] + input[((2i-m-1)/2)+1])/2>input[i]) printf("0");
            else printf("1");
        }
        else{
            if(3*(input[(2i-m-1)/2])>input[i]) printf("0");
            else printf("1");
        }
    }
    return 0;
}



