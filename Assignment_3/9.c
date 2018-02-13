#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int compare(char a[],char b[], int i){
    if(a[i]>b[i]) return 0;
    else if(a[i]<b[i]) return 1;
    else return compare(a,b,i+1);
}

int main()
{
    int i;
    struct myStruct{
        char string[100];
        int length;
    };
    int n;
    scanf("%d",&n);
    struct myStruct array[n];
    for(i=0;i<n;i++){
        scanf("%s",array[i].string);
        array[i].length = strlen(array[i].string);
    }

    while(1==1){
        int flag = 0;
        for(i=0;i<n-1;i++){
            if(array[i].length>array[i+1].length){
                flag = 1;
                struct myStruct temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
            else if(array[i].length==array[i+1].length){
                int comparision = compare(array[i].string,array[i+1].string,0);
                if(comparision==0){
                    flag = 1;
                struct myStruct temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                }
            }
        }
        if(flag==0) break;
    }

    printf("Answer:\n");
    for(i=0;i<n;i++){
        printf("%s\n",array[i].string);
    }

    return 0;
}



