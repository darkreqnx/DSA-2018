#include<stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    int even[n/2+1],odd[n/2];
    int i;
    for(i=0;i<n;i++){
        if(i%2==0) scanf("%d",&even[i/2]);
        else scanf("%d",&odd[i/2]);
    }

    while(1==1){
        int flag = 0;
        for(i=0;i<n/2;i++){
            if(even[i]>even[i+1]){
                int temp = even[i];
                even[i] = even[i+1];
                even[i+1] = temp;
                flag = 1;
            }
        }
        if(flag==0) break;
    }

    while(1==1){
        int flag = 0;
        for(i=0;i<n/2-1;i++){
            if(odd[i]<odd[i+1]){
                int temp = odd[i];
                odd[i] = odd[i+1];
                odd[i+1] = temp;
                flag = 1;
            }
        }
        if(flag==0) break;
    }

    for(i=0;i<n/2+1;i++){
        printf("%d ",even[i]);
    }
    for(i=0;i<n/2;i++){
        printf("%d ",odd[i]);
    }
    return 0;
}
