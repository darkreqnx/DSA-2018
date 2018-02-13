#include<stdio.h>
#include<math.h>
#include<string.h>

void function(int displace){

    char sentence[100];
    printf("Enter string here: ");
    scanf(" %[^\n]s",sentence);
    int length = strlen(sentence);
    int i,oldPosition = length,j,k;

    for(i=length-1;i>-1;i--){
        if(sentence[i]==' ' || i==0){
            if(i==0){
                i--;
            }
            k = oldPosition-1;
            for(j=i+1;j<i+1+((oldPosition-(i+1))/2);j++){
                char temp;
                temp = sentence[j];
                sentence[j] = sentence[k];
                sentence[k--] = temp;
            }

            oldPosition = i;
        }
    }
    for(j=0;j<length;j++){
            if(sentence[j]!=' '){
                int a = (((int)sentence[j]-97+displace)%26);
                if(a<0) a+=26;
                sentence[j] = (char)(a+97);
            }
        }
    printf("\nNew String: %s\n",sentence);

}



int main(){

    int option;
    printf("For encoding, enter 1\nFor decoding, enter 2\nTo exit, enter anything else\nInput: ");
    scanf("%d",&option);
    if(option==1) function(3);
    if(option==2) function(-3);
    if(option!=1 && option!=2) return 0;
    return 0;
}
