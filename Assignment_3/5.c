#include <stdio.h>
#include <stdlib.h>

int five()
{

    int n,m;
    int i;
    scanf("%d %d",&n,&m);
    int tot = 0;
    int lowerBounds[n];
    for(i=0;i<n;i++){
        scanf("%d",&lowerBounds[i]);
        tot-=lowerBounds[i];
    }
    int upperBounds[n];
    for(i=0;i<n;i++){
        scanf("%d",&upperBounds[i]);
        tot+=(upperBounds[i]+1);
    }
    int finalArray[tot];
    int k=0;
    for(i=0;i<n;i++){
        int j = lowerBounds[i];
        while(j<=upperBounds[i]){
           finalArray[k++] = j++;
        }

    }
    while(1==1){
        int flag = 0;
        for(i=0;i<tot;i++){
            if(finalArray[i]>finalArray[i+1]){
                flag = 1;
                int temp = finalArray[i];
                finalArray[i] = finalArray[i+1];
                finalArray[i+1] = temp;
            }
        }
        if(flag==0) break;
    }

    printf("Answer: %d",finalArray[m]);

    return 0;
}


