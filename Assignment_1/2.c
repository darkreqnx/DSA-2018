#include<stdio.h>
#include<math.h>
#include<string.h>

int two(){

    char word[10];
    char sentence[100];
    scanf("%s",word);
    scanf(" %[^\n]s",sentence);

    int sentenceLength = strlen(sentence);
    int wordLength = strlen(word);

    int i,oldPosition=sentenceLength,count=0;
    for(i=sentenceLength-1;i>-1;i--){
        if(sentence[i]==' ' || i==0){
            if(i==0) i--;
            if(oldPosition-(i+1)==wordLength){
                int j,k=0,flag = 0;
                for(j=i+1;j<oldPosition;j++){
                    if(sentence[j]!=word[k++]){
                        flag = 1;
                        break;
                    }
                }
                if(flag==0){
                    count++;
                }
            }
            oldPosition = i;
        }
    }
    printf("%d",count);

    return 0;
}
