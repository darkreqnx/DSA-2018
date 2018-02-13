#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nineteen(){
    char array[10][6] = {{' ','0'},{(char)0,'1'},{'a','b','c','2'},{'d','e','f','3'},{'g','h','i','4'},{'j','k','l','5'},{'m','n','o','6'},{'p','q','r','s','7'},{'t','u','v','8'},{'w','x','y','z','9'}};
    int count=0,i=0;
    char curr;
    char prev = (char)0;
    char arr[100];
    scanf("%[^\n]s",arr);
    int length = strlen(arr);
    while(i<length){
        curr = arr[i++];
        if(curr==prev){
            count++;
            prev = curr;
        }
        else{
            if(prev!=(char)0){
                printf("%c",array[(int)prev-48][count]);
                if((int)curr==32){
                    prev = (char)0;
                    count = 0;
                }
                else{
                    prev = curr;
                    count = 0;
                }
            }
            else{
                prev = curr;
            }
        }
    }
    printf("%c",array[(int)prev-48][count]);
    return 0;
}

