#include<stdio.h>

int seven(){

    int n;
    scanf("%d",&n);
    int arr[n];
    int even = 0,odd = n-1;
    int input;
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&input);
        if(input%2==0) arr[even++] = input;
        else arr[odd--] = input;
    }
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
