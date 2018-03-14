#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int stack1[100], stack2[100];
int top1 = -1,top2 = -1;

int pop1(){
    return stack1[top1--];
}
void push1(int i){
    stack1[++top1] = i;
}
int pop2(){
    return stack2[top2--];
}
void push2(int i){
    stack2[++top2] = i;
}

void enqueue(int i){
    push1(i);
}

int dequeue(){
    if(top1!=-1){
        while(top1!=-1){
            push2(pop1());
        }
        int popped = pop2();
        while(top2!=-1){
            push1(pop2());
        }
        return popped;
    }
    else return -1;
}

void printStack(int i){
    if(i==1){
        for(i=0;i<=top1;i++){
            printf("%d ",stack1[i]);
        }
    }
    else if(i==2){
        for(i=0;i<=top2;i++){
            printf("%d ",stack2[i]);
        }
    }
    else printf("Wrong choice!");
}

int fiveA()
{
    while(1==1){
        int choice;
        printf("\n1. Enqueue an item\n2. Dequeue an item\n3. Print Stack\n4. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("\nEnter item to enqueue: ");
            int i;
            scanf("%d",&i);
            enqueue(i);
        }
        else if(choice==2){
            int i = dequeue();
            if(i==-1) printf("No elements in queue");
            else printf("Dequeued element = %d",i);
        }
        else if(choice==3){
            printf("\nEnter stack number to print (1 or 2): ");
            int i;
            scanf("%d",&i);
            printStack(i);
        }
        else if(choice==4){
            goto EXIT;
        }
        else printf("\nWrong choice");
    }
EXIT:    return 0;
}



