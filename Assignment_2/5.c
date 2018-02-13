#include <stdio.h>
#include <stdlib.h>
int five(){

    int array[6][6];
    int i,j;
    int count=0;
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            scanf("%d",&array[i][j]);
            if(array[i][j]!=0) count++;
        }
    }
    if(count<10){
        for(i=0;i<6;i++){
            for(j=0;j<6;j++){
               if(array[i][j]!=0){
                printf("%d %d %d\n",i,j,array[i][j]);
               }
            }
        }
        printf("\n\n");
        for(i=0;i<6;i++){
            for(j=0;j<6;j++){
               if(array[j][i]!=0){
                printf("%d %d %d\n",i,j,array[j][i]);
               }
            }
        }
    }
    else{
        printf("Not a sparse matrix");
    }
    return 0;
}

