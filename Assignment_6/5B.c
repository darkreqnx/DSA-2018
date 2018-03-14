#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int queue1[100], queue2[100];
int top1=-1, top2=-1;
int start1=0,start2=0;

void enqueue1(int i){
    queue1[++top1] = i;
}


void enqueue2(int i){
    queue2[++top2] = i;
}

int dequeue1(){
    return queue1[start1++];
}
int dequeue2(){
    return queue2[start2++];
}

void push(int i){
    enqueue1(i);
}

int pop(){
    if(start1<=top1){
        while(start1<top1){
            enqueue2(dequeue1());
        }
        int element = dequeue1();
        top1 = -1;
        start1 = 0;
        while(start2<=top2){
            enqueue1(dequeue2());
        }
        top2 = -1;
        start2 = 0;
        return element;
    }
    else return -1;
}

void printQueue(int i){
    if(i==1){
        for(i=0;i<=top1;i++){
            printf("%d ",queue1[i]);
        }
    }
    else if(i==2){
        for(i=0;i<=top2;i++){
            printf("%d ",queue2[i]);
        }
    }
    else printf("Wrong choice!");
}

int fiveB()
{
    while(1==1){
        int choice;
        printf("\n1. Insert an item\n2. Pop an item\n3. Print Queue\n4. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("\nEnter item to insert: ");
            int i;
            scanf("%d",&i);
            push(i);
        }
        else if(choice==2){
            int i = pop();
            if(i==-1) printf("No elements in stack");
            else printf("Popped element = %d",i);
        }
        else if(choice==3){
            printf("\nEnter queue number to print (1 or 2): ");
            int i;
            scanf("%d",&i);
            printQueue(i);
        }
        else if(choice==4){
            goto EXIT;
        }
        else printf("\nWrong choice");
    }
EXIT:    return 0;
}
