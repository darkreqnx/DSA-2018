/*
  Tanmay Mody
  March 15, 2018
  CIS2107
  Assignment 7
  To write String Functions
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#define SIZE 100


void upperLower() {

    printf("Enter string: ");
    char s[SIZE];
    scanf("%s",s);
    int i;
    for (i = 0; i <SIZE ; i++) {
        s[i] = toupper(s[i]);
    }
        printf("Upper Case: ");
        printf("%s\n", s);

    for (i = 0; i <SIZE ; i++) {
        s[i] = tolower(s[i]);
    }
    printf("Lower Case: ");
    printf("%s\n", s);
}

void convertStrtoInt() {

    printf("Enter the total number of numbers: ");
    int n;
    scanf("%d", &n);
    int i;
    int total = 0;
    for(i=0;i<n;i++){
        printf("Enter number %d: ",i+1);
        char a[SIZE];
        scanf("%s",a);
        total+=atoi(a);
    }

    printf("The total is: %d", total);
}

void convertStrtoFloat() {

    printf("Enter the total number of numbers: ");
    int n;
    scanf("%d", &n);
    int i;
    float total = 0;
    for(i=0;i<n;i++){
        printf("Enter number %d: ",i+1);
        char a[SIZE];
        scanf("%s",a);
        total+=atof(a);
    }

    printf("The total is: %.2f", total);
}

void compareStr() {
    int result;
    char s1[SIZE];
    char s2[SIZE];

    printf("String 1: ");
    scanf("%s", s1);

    printf("String 2: ");
    scanf("%s", s2);

    result = strcmp(s1, s2);
    printf(" \n");

    if (result > 0)
    {
      printf("String 1 is greater\n");
    }
    else if(result < 0)
    {
      printf("String 2 is greater\n");
    }
    else
    {
        printf("Both are equal");
    }

}

void  comparePartialStr() {

    int n;
    char s1[SIZE];
    char s2[SIZE];

    printf(" Enter the number of characters you would like to compare: ");
    scanf("%d", &n);

    printf("Please enter the first sentence: ");
    scanf("%s", s1);

    printf("Please enter the second sentence: ");
    scanf("%s", s2);

    int result = strncmp(s1,s2,n);

    if (result < 0)
    {
      printf("String 1 is shorter\n");
    }
    else if(result > 0)
    {
      printf("String 2 is shorter\n");
    }
    else
    {
      printf("Both are equal");
    }

}


void tokenizeTelNum() {

    char string[50] ="(123) 456-7890";
    char *p;

    p = strtok (string," ()-");
    printf("After ...  ");

    while (p!= NULL)
    {
        printf ("%s",p);
        p = strtok (NULL, " ()-");
    }

}

void reverse() {
    printf("Enter string: ");
    char s[SIZE];
    scanf("%s",s);
    int length = strlen(s);

    int i;
    printf("The reversed String is: ");

    for(i=0;i<length/2;i++){
        char temp = s[i];
        s[i] = s[length-i-1];
        s[length-i-1] = temp;
    }

    printf("%s",s);
}

void countSubstr() {

    char string[SIZE], substr[15];
    printf("Enter string: ");
    scanf("%s",string);
    printf("Enter substr: ");
    scanf("%s",substr);

    char * i = &string[0];

    int total=0;
    while ( (i=strstr(i,substr)) != NULL )
    {
        total++;
        i++;
    }
    printf("SubString is found %d times in the String", total);

}

void countChar() {

    char string[SIZE], c;
    printf("Enter string: ");
    scanf("%s",string);
    char blank;
    scanf("%c",&blank);
    printf("Enter character: ");
    scanf("%c",&c);

    char * i = &string[0];

    int total=0;
    while ( (i=strchr(i,c)) != NULL )
    {
        total++;
        i++;
    }
    printf("Character is found %i times in the String", total);

}

void countAlpha() {
    printf("Enter string: ");
    char string[SIZE];
    scanf("%s",string);

    int c = 0, count[26] = {0}, x;

    printf("Counting the amount of times letters in the alphabet occur");
    printf(" \n");

    while (string[c] != '\0') {
        if (string[c] >= 'a' && string[c] <= 'z') {
            x = string[c] - 'a';
            count[x]++;
        }
        else if (string[c] >= 'A' && string[c] <= 'Z') {
            x = string[c] - 'A';
            count[x]++;
        }
        c++;
    }
    for (c = 0; c < 26; c++)
        printf("%c occurs %d times in the string.\n", c>'a'?c+'a':c+'A', count[c]);
}

void countWords(){
  printf("Enter String: ");
  char p[SIZE];
  char blank;
  scanf("%c",&blank);
  scanf("%[^\n]s",p);

  char words[100];
  int count = 0;
  char *tokens = strtok(p, " ");
  strcpy(words, tokens);

  printf("The following words are present:\n");
  while(tokens !=NULL){
    count++;
    strcpy(words, tokens);
    printf("%s\n", words);
    tokens = strtok(NULL, " ");
  }

  printf("The number of words is: %d\n", count);
}


void startsWithB() {
    printf("Enter number of words: ");
    int n;
    scanf("%d",&n);
    int i;
    char s[n][100];
    for(i=0;i<n;i++){
        printf("Enter word %d: ",i+1);
        scanf("%s",s[i]);
    }

    printf("Strings that started with B were: \n");

    for (i = 0; i <n; i++) {
        if(s[i][0]=='b'){
            printf("%s\n", s[i]);
        }
    }
}

void endsWithed() {
    printf("Enter number of words: ");
    int n;
    scanf("%d",&n);
    int i;
    char s[n][100];
    for(i=0;i<n;i++){
        printf("Enter word %d: ",i+1);
        scanf("%s",s[i]);
    }

    printf("Strings that ended in -ed were: ");

    for (i = 0; i <n; i++) {
        int l = strlen(s[i]);
        if(s[i][l-1] == 'd' && s[i][l-2] == 'e') {
            printf("%s\n", s[i]);
        }
    }
}
int main() {


    printf("\n\t\tUpperLower\n");
    upperLower();
    printf("\n");

    printf("\n\t\tConvertStrtoInt\n");
    convertStrtoInt();
    printf("\n");

    printf("\n\t\tConvertStrtoFloat\n");
    convertStrtoFloat();
    printf("\n");

    printf("\n\t\tString comparision\n");
    compareStr();
    printf("\n");

    printf("\n\t\tString comparision by number\n");
    comparePartialStr();
    printf("\n");

    printf("\n\t\tToken telephone number\n");
    tokenizeTelNum();
    printf("\n");

    printf("\n\t\tReverse Method\n");
    reverse();
    printf("\n");

    printf("\n\t\tCount Substring\n");
    countSubstr();
    printf("\n");

    printf("\n\t\tCounts character\n");
    countChar();
    printf("\n");

    printf("\n\t\tCount Alpha\n");
    countAlpha();
    printf("\n");

    printf("\n\t\tCount words\n");
    countWords();

    printf("\n\t\tStarts with 'B' or 'b'\n");
    startsWithB();
    printf("\n");

    printf("\n\t\tEnds with 'ed'\n");
    endsWithed();
    printf("\n");

    return 0;
}
