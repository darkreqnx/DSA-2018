#include<stdio.h>

int one(){

    int n;
    scanf("%d",&n);
    int arr[n],count[n];
    int i,j;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        int flag = 0;
        for(j=0;j<i;j++){
            if(arr[i]==arr[j]){
                count[j]++;
                count[i] = 0;
                flag = 1;
                break;
            }
        }
        if(flag==0){
            count[i] = 1;
        }
    }

    while(1==1){
        int flag = 0;
        for(i=0;i<n-1;i++){
            if(count[i+1]>count[i]){
                flag = 1;

                int temp = count[i];
                count[i] = count[i+1];
                count[i+1] = temp;

                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    if(flag==0) break;
    }

    for(i=0;i<n;i++){
        for(j=0;j<count[i];j++){
            printf("%d ",arr[i]);
        }
    }

    return 0;
}
