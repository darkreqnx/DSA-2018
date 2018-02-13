#include<stdio.h>

int four(){

    int n;
    scanf("%d",&n);
    int in[n],out[n];
    int arr[25]={0};
    int i,j;
    for(i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&out[i]);
    }
    for(i=0;i<n;i++){
        for(j=in[i];j<=out[i];j++){
            arr[j]++;
        }
    }
    int max=0;
    j=0;
    for(i=0;i<25;i++){
        if(arr[i]>max){
            max=arr[i];
            j=i;
        }
    }
    printf("%d",j);
    return 0;
}
