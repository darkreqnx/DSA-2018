#include<stdio.h>

int ten(){

    int array[400]={0}, carry[400]={0};
    int tos=-1;
    int i,j,n;
    scanf("%d",&n);
    array[++tos] = 1;
    for(i=1;i<=n;i++){
        for(j=0;j<=tos+1;j++){
            carry[j]=0;
        }
        for(j=0;j<=tos;j++){
            array[j] = (array[j]*i)+carry[j];
            if(array[j]>=10){
                carry[j+1] = array[j]/10;
                array[j]%=10;
                if(j==tos) tos++;
            }
        }
    }
    for(i=tos;i>=0;i--){
        printf("%d",array[i]);
    }

    return 0;
}
