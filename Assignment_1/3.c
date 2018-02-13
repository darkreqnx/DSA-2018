#include<stdio.h>
#include<math.h>
#include<string.h>

int three(){

    struct myStruct{
        char c;
        int f;
    };

    struct myStruct ms[100];
    int count=0,i;
    char lastRead = 'a';

    while(lastRead!='\n'){
        int flag = 0;
        char character;
        scanf("%c",&character);
        for(i=0;i<count;i++){
            if(ms[i].c==character){
                flag = 1;
                ms[i].f++;
            }
        }
        if(flag==0){
            struct myStruct temp;
            temp.c = character;
            temp.f = 1;
            ms[count++] = temp;
        }
        lastRead = character;
    }

    for(i=0;i<count;i++){
        if(ms[i].c!='\n') printf("%c %d\n",ms[i].c,ms[i].f);
    }

    return 0;
}
