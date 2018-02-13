#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[],int e, int l, int r){
    if(arr[(l+r)/2]==e) return (l+r)/2;
    if(arr[(l+r)/2]<e) binarySearch(arr,e,(l+r)/2,r);
    else binarySearch(arr,e,l,(l+r)/2);
}

int six(){

    int n,m;
    scanf("%d %d",&n,&m);
    int i;
    int arrn[n],arrm[m];
    for(i=0;i<n;i++){
        scanf("%d",&arrn[i]);
    }
    for(i=0;i<m;i++){
        scanf("%d",&arrm[i]);
    }

    while(1==1){
        int flag = 0;
        for(i=0;i<n-1;i++){
            if(arrn[i]>arrn[i+1]){
                flag = 1;
                int temp = arrn[i];
                arrn[i] = arrn[i+1];
                arrn[i+1] = temp;
            }
        }
        if(flag==0) break;
    }

    int printed[n];
    for(i=0;i<n;i++){
        printed[i]=0;
    }

    for(i=0;i<m;i++){
        int z = binarySearch(arrn,arrm[i],0,n-1);
        printf("%d ",arrn[z]);
        printed[z] = 1;
        int temp = z-1;
        while(arrn[temp]==arrm[i]){
            printf("%d ",arrn[temp]);
            printed[temp--] = 1;
        }
        temp = z+1;
        while(arrn[temp]==arrm[i]){
            printf("%d ",arrn[temp]);
            printed[z++] = 1;
        }

    }
    for(i=0;i<n;i++){
        if(printed[i]==0) printf("%d ",arrn[i]);
    }
    return 0;
}
