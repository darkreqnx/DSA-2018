#include<stdio.h>
#include<math.h>

int main()
{
    int carry[50]={0},arr[50],ans[50]={0};
    int i=0,number,top=0;
    scanf("%d",&number);
    while(number!=0){
        arr[i++] = number%10;
        number/=10;
    }
    i=0;
    while(1==1){
        ans[i] = ((number*arr[i])+carry[i])%10;
        carry[i+1] = ((number*arr[i])+carry[i])/10;
        top++;
        i++;
        if(arr[i]==0 && carry[i]==0) break;
    }
    for(i=0;i<=top;i++){
        printf("%d",ans[i]);
    }
}
