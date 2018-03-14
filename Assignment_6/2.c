#include <stdio.h>
#include <stdlib.h>
#include<string.h>

long long int factorial(int n){
    if(n==1 || n==0) return 1;
    else return n*factorial(n-1);
}

int two()
{
    printf("Enter String: ");
    char input[100000];
    scanf("%s",input);
    printf("Enter number of days: ");
    int days;
    scanf("%d",&days);
    int i;
    int choice[days][2];
    for(i=0;i<days;i++){
        printf("Enter left and right for day %d: ",i+1);
        scanf("%d %d",&choice[i][0],&choice[i][1]);
    }

    int j;
    for(j=0;j<days;j++){
        int array[26] = {0};
        for(i=choice[j][0]-1;i<choice[j][1];i++){
            array[(int)input[i]-97]++;
        }
        int oddFreqs=0;
        for(i=0;i<26;i++){
            if(array[i]%2==1) oddFreqs++;
        }
        int sum = 0;
        for(i=0;i<26;i++){
            if(array[i]%2==0) sum+=(array[i]/2);
            else sum+=((array[i]-1)/2);
        }
        long long int numerator = factorial(sum);
        long long int denominator = 1;
        for(i=0;i<26;i++){
            if(array[i]%2==0) denominator*=factorial(array[i]/2);
            else denominator*=factorial((array[i]-1)/2);
        }
        long long int ans = numerator/denominator;
        if(oddFreqs!=0) ans*=oddFreqs;
        int answer = ans%1000000000;
        printf("Answer for day %d: %d\n",j,answer);
    }


    return 0;
}

