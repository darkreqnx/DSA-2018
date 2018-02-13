#include<stdio.h>
#include<string.h>


int location=0;
int length;
char message[7] = {'g','o','o','d','b','y','e'};
char garbage[100];
int msgLoc=0;

int answer(){
    int count=0;
    while(location!=length){
        if(garbage[location]==message[msgLoc]){
            count++;
            location++;
            msgLoc++;
        }
        else{
            location++;
        }
    }
    if(count==7) return 1;
    else return 0;
}
int eight(){

    scanf("%s",garbage);
    length = strlen(garbage);
    int b = answer();
    if(b==1) printf("Yes");
    else printf("No");
    return 0;
}
