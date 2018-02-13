#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct tower{
        int height;
        int cost;
    };

int search(struct tower * pointer,int l, int r,int length){

    int m = (l+r)/2;
    int cost=0,costLeft=0,costRight=0;
    int i;
    if(l!=r){
        for(i=0;i<length;i++){
            cost+=abs((*(pointer+i)).height - (*(pointer+m)).height) * (*(pointer+i)).cost;
            costLeft+=abs((*(pointer+i)).height - (*(pointer+m-1)).height) * (*(pointer+i)).cost;
            costRight+=abs((*(pointer+i)).height - (*(pointer+m+1)).height) * (*(pointer+i)).cost;
        }
        //printf("Test: %d %d\n",cost,costRight);
    if (costLeft<cost) return search(pointer,l,m-1,length);
    else if (costRight<cost) return search(pointer,m+1,r,length);
    else return cost;
    }
    else{
        for(i=0;i<length;i++){
            cost+=abs((*(pointer+i)).height - (*(pointer+m)).height) * (*(pointer+i)).cost;
        }
        //printf("Test: %d %d\n",cost,costRight);
        return cost;
    }

}

int one()
{
    int t;
    scanf("%d",&t);
    struct tower *testCase[t];
    int testSize[t];
    int i,j;
    for(i=0;i<t;i++){
        scanf("%d",&testSize[i]);
        testCase[i] = (struct tower *)malloc(testSize[i]*(sizeof(struct tower)));
        for(j=0;j<testSize[i];j++){
            scanf("%d",&((*(testCase[i]+j)).height));
        }
        for(j=0;j<testSize[i];j++){
            scanf("%d",&((*(testCase[i]+j)).cost));
        }
        while(1==1){
            int flag = 0;
            for(j=0;j<testSize[i]-1;j++){
                if((*(testCase[i]+j)).height > (*(testCase[i]+j+1)).height){
                    struct tower temp = *(testCase[i]+j);
                    *(testCase[i]+j) = *(testCase[i]+j+1);
                    *(testCase[i]+j+1) = temp;
                    flag = 1;
                }
            }
            if(flag==0){
                break;
            }
        }
    }

    for(i=0;i<t;i++){
        printf("\nSolution: %d\n",search(testCase[i],0,testSize[i]-1,testSize[i]));
    }
    return 0;
}


