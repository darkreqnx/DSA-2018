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
#define SIZE 100


void upperLower() {

    char s[SIZE] = "how do you think I am doing in this class?";
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

    char a[SIZE] = "8";
    char b[SIZE] = "4";
    char c[SIZE] = "87";
    char d[SIZE] = "102";

    int aa = atoi(a);
    int bb = atoi(b);
    int cc = atoi(c);
    int dd = atoi(d);

    int total = aa+bb+cc+dd;

    printf("The total is: %d", total);
}

void convertStrtoFloat() {

    char a[SIZE] = "24.4";
    char b[SIZE] = "51.9";
    char c[SIZE] = "46.6";
    char d[SIZE] = "210.8";

    float aa = atof(a);
    float bb = atof(b);
    float cc = atof(c);
    float dd = atof(d);

    float total = aa+bb+cc+dd;

    printf("The total is: %.2f", total);
}

void compareStr() {
    int result;
    char s1[SIZE];
    char s2[SIZE];

    printf("String 1 \n");
    scanf("%s", s1);

    printf("String 2 \n");
    scanf("%s", s2);

    int s1Size = strlen(s1);
    int s2Size = strlen(s2);

    result = strcmp(s1, s2);
    puts(" \n");

    if (s1Size < s2Size)
    {
      printf("String 1 is shorter\n");
    }
    else if(s1Size > s2Size)
    {
      printf("String 2 is shorter\n");
    }
    else
    {
      printf("Both are equal");
    }

}

void  comparePartialStr() {

    int n;
    int result;
    char s1[SIZE];
    char s2[SIZE];
    char modifiedString[SIZE];


    printf(" Enter the number of characters you would like to compare\n");
    scanf("%d", &n);

    printf("Please enter the first word \n");
    scanf("%s", s1);

    printf("Please enter the second word \n");
    scanf("%s", s2);

    int i;
    for (i = 0; i < n; ++i) {
        modifiedString[i] = s1[i];
    }

    result = strcmp(modifiedString,s2);
    int modSize = strlen(modifiedString);
    int s2Size = strlen(s2);

    if (modSize < s2Size)
    {
      printf("String 1 is shorter\n");
    }
    else if(modSize > s2Size)
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
    char s[] = "Yeay I scored an A";
    int length = strlen(s);

    int i;
    printf("The reversed String is: ");

    for (i = length - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            s[i] = '\0';
            printf("%s ", &(s[i]) + 1);
        }
    }
    printf("%s\n", s);
}

void countSubstr() {

    char *i="I was up till six am to do this lab";
    int total=0;
    while ( (i=strstr(i,"a")) != NULL )
    {
        total++;
        i++;
    }
    printf("SubString is found %d times in the String", total);

}

void countChar() {

    char *i="We say many different things to do mosaics";
    int total=0;
    while ( (i=strchr(i,'H')) != NULL )
    {
        total++;
        i++;
    }
    printf("Character is found %i times in the String", total);

}

void countAlpha() {
    char string[100] = "hey handsome, how you doing?";
    int c = 0, count[26] = {0}, x;

    printf("Counting the amount of times letters in the alphabet occur");
    printf(" \n");

    while (string[c] != '\0') {
        if (string[c] >= 'a' && string[c] <= 'z') {
            x = string[c] - 'a';
            count[x]++;
        }
        c++;
    }
    for (c = 0; c < 26; c++)
        printf("%c occurs %d times in the string.\n", c + 'a', count[c]);


}

void countWords(char * p){
  printf("String: %s\n", p);
  char words[100];
  int count = 0;
  char *tokens = strtok(p, " ");
  strcpy(words, tokens);

  while(tokens !=NULL){
    count++;
    strcpy(words, tokens);
    printf("words is: %s\n", words);
    tokens = strtok(NULL, " ");
  }

  printf("The number of words is: %d\n", count);
}

void startsWithB() {
    char s[3][100] = {"babulo", "banana", "frat"};
    int loop = strlen(s);
    char z[] = "b";
    char *ret;
    int i;

    printf("Strings that started with B were: ");

    for (i = 0; i <loop; ++i) {
        ret= strstr(s[i], z);
        if (ret != NULL) {
            printf("%s\n", s[i]);
        }
    }
}

void endsWithed() {
    char s[5][100]= {"hurried", "likhin", "modicare", "flipped", "Hurrcane"};
    int length = strlen(s);
    char z[] = "ed";
    char *ret;
    int i;

    printf("Strings that ended in -ed were: ");

    for (i = 0; i <length; i++) {
        ret= strstr(s[i],z);
        if(ret != NULL) {
            printf("%s\n", s[i]);
        }
    }
}
int main() {


    puts("\t\tUpperLower");
    upperLower();
    puts("");

    puts("\t\tConvertStrtoInt");
    convertStrtoInt();
    puts("\n");

    puts("\t\tConvertStrtoFloat");
    convertStrtoFloat();
    puts("\n");

    puts("\t\tString comparision");
    compareStr();
    puts("\n");

    puts("\t\tString comparision by number");
    comparePartialStr();
    puts("");

    puts("\t\tToken telephone number");
    tokenizeTelNum();
    puts("");

    puts("Reverse Method");
    reverse();
    puts("");

    puts("Count Substring");
    countSubstr();
    puts("\n");

    puts("Counts character");
    countChar();
    puts("\n");

    puts("Count Alpha");
    countAlpha();
    puts("\n");

    /*puts("Count words");
    countWords("I have a major adharma");
    puts("");
*/
    startsWithB();
    puts("");

    endsWithed();
}
