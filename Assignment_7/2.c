#include <stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    int arr[n][3];
    int i;
    for(i=0;i<n;i++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
        arr[i][2] = 0;
    }

    //Sort by arrival time
    while(1==1){
        int flag = 0;
        for(i=0;i<n-1;i++){
            if(arr[i][0]>arr[i+1][0]){
                int temp = arr[i][1];
                arr[i][1] = arr[i+1][1];
                arr[i+1][1] = temp;

                temp = arr[i][0];
                arr[i][0] = arr[i+1][0];
                arr[i+1][0] = temp;

                flag = 1;
            }
        }
        if(flag==0) break;
    }

    //Shortest Job Next
    int currentTime = arr[0][0];
    int sum = 0;
    int count = 0;
    while(count!=n){
        int j=-1;
        for(i=0;i<n;i++){
            if(arr[i][0]>currentTime)   break;
            if(arr[i][2]==0 && (j=-1 || (j!=-1 && arr[i][1]<arr[j][1]))){
                j = i;
            }
        }
        currentTime+=arr[j][1];
        sum+=(currentTime-arr[j][0]);
        count++;
        arr[j][2]=1;
    }
    printf("Avg. Waiting time is: %d",sum/n);
    return 0;
}
