#include<stdio.h>

void merge(int arr[],int l,int m,int r){

    int i,j,k;
    int arr1[m-l+1],arr2[r-m];
    for(i=0;i<m-l+1;i++){
        arr1[i] = arr[i+l];
    }
    for(i=0;i<r-m;i++){
        arr2[i] = arr[i+m+1];
    }
    i=0;j=0;k=l;
    while(i<m-l+1 && j<r-m){
        if(arr1[i] < arr2[j]){
            arr[k] = arr1[i];
            i++;k++;
        }
        else{
            arr[k] = arr2[j];
            j++;k++;
        }
    }
    while(i<m-l+1){
        arr[k] = arr1[i];
        i++;k++;
    }
    while(i<r-m){
        arr[k] = arr2[j];
        j++;k++;
    }
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int search(int arr[],int e,int l, int r){
    if(l<r){
        if(arr[(l+r)/2]==e)return (l+r)/2;
        else if(arr[(l+r)/2]<e) return search(arr,e,(l+r)/2+1,r);
        else return search(arr,e,l,(l+r)/2-1);
    }
    else{
        return -1;
    }
}

int two(){
    int n,x;
    scanf("%d %d",&n,&x);
    int arr[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    int flag = 0;
    for(i=0;i<n;i++){
        int req = x-arr[i];
        int response = search(arr,req,0,n-1);
        if(response!=-1){
            flag = 1;
            break;
        }
    }
    if(flag==1) printf("Yes");
    else printf("No");
    return 0;
}

