#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int three(){

    char program[1000];
    scanf("%[^\n]s",program);
    int length = strlen(program);
    int start[10] = {-1};
    int end[10] = {-1};
    int i,j=0;
    for(i=0;i<length;i++){
        if(program[i]=='/' && program[i+1]=='*') start[j] = i;
        if(program[i]=='*' && program[i+1]=='/') end[j++] = i+1;
    }
    j=0;
    for(i=0;i<length;i++){
        if(i==start[j]) i=end[j++]+1;
        printf("%c",program[i]);
    }
    return 0;
}
