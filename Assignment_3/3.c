#include <stdio.h>
#include <stdlib.h>

int three()
{
    int filingCabinets,friends,sum=0;
    int i;
    scanf("%d %d",&filingCabinets,&friends);
    int folders[filingCabinets];
    for(i=0;i<filingCabinets;i++){
        scanf("%d",&folders[i]);
        sum+=folders[i];
    }
    while(1==1){
        int flag = 0;
        for(i=0;i<filingCabinets-1;i++){
            if(folders[i]>folders[i+1]){
                flag = 1;
                int temp = folders[i];
                folders[i] = folders[i+1];
                folders[i+1] = temp;
            }
        }
        if(flag==0) break;
    }

    int approx = sum/friends;
    int max = 0;
    sum = 0;
    for(i=0;i<filingCabinets;i++){
        if(abs(sum-approx)>abs(sum+folders[i]-approx)){
            sum+=folders[i];
            if(sum>max) max = sum;
        }
        else{
            sum = folders[i];
        }
    }

    printf("\nMax = %d\n",max);

    return 0;
}

