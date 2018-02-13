#include <stdio.h>
#include <stdlib.h>

int charToInt(char c){
    if(c>='a' && c<='z'){
        return (int)c-97;
    }
    if(c>='0' && c<='9'){
        return (int)c-48+27;
    }
    if(c==' ') return 26;
    if(c=='\n') return -1;
}

int eighteen(){
    int array[] = {2,22,222,3,33,333,4,44,444,5,55,555,6,66,666,7,77,777,7777,8,88,888,9,99,999,9999,0,00,11,2222,3333,4444,5555,6666,77777,8888,99999};
    char c;
    int prev;
    scanf("%c",&c);
    prev = array[charToInt(c)];
    printf("%d",prev);
    while(c!='\n'){
        int curr;
        scanf("%c",&c);
        curr = charToInt(c);
        if(curr==-1) break;
        curr = array[curr];
        if(curr%10==prev%10) printf(" ");
        printf("%d",curr);
        prev = curr;
    }
    return 0;
}
