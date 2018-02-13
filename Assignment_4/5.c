#include<stdio.h>
#include<math.h>

int five(){

    struct numfact{

        int num;
        int fact;
    };

    int n;
    scanf("%d",&n);
    struct numfact arr[n];
    int i,j;
    for(i=0;i<n;i++){
        scanf("%d",&(arr[i].num));
        arr[i].fact = 0;
        int root = (int)sqrt(arr[i].num);
        for(j=1;j<=root;j++){
            if(arr[i].num%j==0){
                arr[i].fact+=2;
                if(j==root && (double)root == sqrt(arr[i].num)) arr[i].fact--;
            }
        }
    }

    while(1==1){
        int flag = 0;
        for(i=0;i<n-1;i++){
            if(arr[i].fact>arr[i+1].fact){
                struct numfact temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag = 1;
            }
        }
        if(flag==0) break;
    }

    for(i=0;i<n;i++){
        printf("%d ",arr[i].num);
    }
    return 0;
}
