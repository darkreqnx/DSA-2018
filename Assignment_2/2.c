#include <stdio.h>
#include <stdlib.h>

int two()
{
    int cardNumber[16];
    int i=0,count=-1,sum=0;
    char c = 'a';
    while(c!='\n'){
        count++;
        scanf("%c",&c);
        cardNumber[i++] = (int)c - 48;
    }
    for(i=count-2;i>=0;i-=2){
        cardNumber[i] = cardNumber[i]*2;
        if(cardNumber[i]>10){
            int z = cardNumber[i]%10;
            cardNumber[i] = (cardNumber[i]/10)+z;
        }
        sum+=(cardNumber[i]+cardNumber[i+1]);
    }
    printf("%d\n",sum);
    if(sum%10==0){
        printf("Valid");

    }
    else{
        printf("Invalid");
    }
}
