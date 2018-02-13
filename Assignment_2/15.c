#include<stdio.h>
#include<math.h>

int arr[50]={0};
int number,originalNumber,count;
void function(){
    int carry[50]={0},ans[50]={0};
    int i=0,top=0;
    count=0;
    originalNumber = number;
    while(number!=0){
        count++;
        arr[i++] = number%10;
        number/=10;
    }
    number = originalNumber;
    i=0;
    while(1==1){
        ans[i] = ((number*arr[i])+carry[i])%10;
        carry[i+1] = ((number*arr[i])+carry[i])/10;
        top++;
        i++;
        if(arr[i]==0 && carry[i]==0) break;
    }
    if(count%2==1){
        if(top%2==0) top++;
        int j=0;
        for(i=(top/2)+(count/2);i>=(top/2)-(count/2);i--){
            arr[j++] = ans[i];
        }
    }
    if(count%2==0){
        if(top%2==1) top++;
        int j=0;
        for(i=(top/2-1)+(count/2);i>(top/2-1)-(count/2);i--){
            arr[j++] = ans[i];
        }
    }

    for(i=0;i<count;i++){
        printf("%d",arr[i]);
    }
}

int main()
{
    int i,j,k;
    printf("Enter initial seed: ");
    scanf("%d",&number);
    printf("Enter number of random numbers to be generated: ");
    scanf("%d",&k);
    for(i=0;i<k;i++){
        function();
        printf("\n");
        double num = 0;
        for(j=0;j<count;j++){
            num+=(arr[j]*pow(10,count-j-1));
        }
        number = num;
    }

    return 0;
}

