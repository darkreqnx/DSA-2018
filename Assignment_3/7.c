#include <stdio.h>
#include <stdlib.h>

void merge(int array[],int l,int m,int r){

    int i,j,k;
    int arr1[m-l+1],arr2[r-m];
    for(i=0;i<m-l+1;i++){
        arr1[i] = array[i+l];
    }
    for(i=0;i<r-m;i++){
        arr2[i] = array[i+m+1];
    }
    i=0;
    j=0;
    k=l;
    while(i<(m-l+1) && j<(r-m)){
        if(arr1[i] < arr2[j]){
            array[k] = arr1[i];
            i++;
            k++;
        }
        else{
            array[k] = arr2[j];
            j++;
            k++;
        }
    }
    while(i<(m-l+1)){
        array[k] = arr1[i];
        i++;
        k++;
    }
    while(j<(r-m)){
        array[k] = arr2[j];
        j++;
        k++;
    }

}

void invmerge(int array[],int l,int m,int r){

    if(r==l+1){
        int temp = array[r];
        array[r] = array[l];
        array[l] = temp;
        return;
    }

    int i=0,j=0,k=l;
    int arr1[m-l+1],arr2[r-m];
    for(i=l;i<=r;i+=2){
        arr1[j] = array[i];
        if(i!=r) arr2[j] = array[i+1];
        j++;
    }
    k=l;
    for(i=0;i<m-l+1;i++){
        array[k++] = arr1[i];
    }
    for(i=0;i<r-m;i++){
        array[k++] = arr2[i];
    }

}

void mergesort(int array[],int l, int r){

    int m = (l+r)/2;
    if(l<r){
        mergesort(array,l,m);
        mergesort(array,m+1,r);
        merge(array,l,m,r);
    }
}

void invmergesort(int array[],int l, int r){

    int m = (l+r)/2;
    if(l<r){
        invmerge(array,l,m,r);
        invmergesort(array,l,m);
        invmergesort(array,m+1,r);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    int array[n];
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    mergesort(array,0,n-1);
    invmergesort(array,0,n-1);
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    return 0;
}




