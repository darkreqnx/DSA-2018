#include<stdio.h>

int three(){

    struct numpos{
        int num;
        int pos;
    };

    int n;
    scanf("%d",&n);
    struct numpos arr[n];
    int considered[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&(arr[i].num));
        arr[i].pos = i;
        considered[i] = 0;
    }

    while(1==1){
        int flag = 0;
        for(i=0;i<n-1;i++){
            if(arr[i].num>arr[i+1].num){
                struct numpos temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag = 1;
            }
        }
        if(flag==0) break;
    }

    int count=0;

    for(i=0;i<n;i++){
        if(considered[i]==0 && arr[i].pos != i){
            considered[i] = 1;
            int j = arr[i].pos;;
            while(considered[j]==0){
                count++;
                j = arr[j].pos;
            }

        }
    }

    printf("%d",count);

    return 0;
}
