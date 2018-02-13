#include<stdio.h>
#include<math.h>
#include<string.h>

int one(){
    char originalString[100];
    scanf("%s",originalString);
    int length = strlen(originalString);
    int rootLength = (int)sqrt(length);
    if(rootLength*rootLength==length){
            char array[rootLength][rootLength];
        int i,j,a=0;
        for(i=0;i<rootLength;i++){
            for(j=0;j<rootLength;j++){
                array[i][j] = originalString[a++];
            }
        }

        char chk1[length],chk2[length],chk3[length];
        j=length;
        for(i=0;i<length;i++){
            chk1[--j] = originalString[i];
        }
        a=0;
        for(i=0;i<rootLength;i++){
            for(j=0;j<rootLength;j++){
                chk2[a++] = array[j][i];
            }
        }
        j=length;
        for(i=0;i<length;i++){
            chk3[--j] = chk2[i];
        }

        int flag = 0;

        for(i=0;i<length;i++){
            if(originalString[i]!=chk1[i] || originalString[i]!=chk2[i] || originalString[i]!=chk3[i] ){
                flag = 1;
                break;
            }
        }

        if(flag==0){
            printf("Yes");
        }
        else{
            printf("No");
        }

    }
    return 0;
}
