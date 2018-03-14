#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct doublyLinkedList{
    struct doublyLinkedList * left;
    int data;
    struct doublyLinkedList * right;
};

struct doublyLinkedList * head = 0;
struct doublyLinkedList * tail = 0;

void insert(int data, int location){
    struct doublyLinkedList myStruct;
    myStruct.data = data;
    myStruct.left = 0;
    myStruct.right = 0;
    if(location==0){
        myStruct.right = head;
        (*head).left = &myStruct;
        head = &myStruct;
    }
    if(location==1){
        myStruct.left = tail;
        (*tail).right = &myStruct;
        tail = &myStruct;
    }

}

int del(int location){
    int i;
    if(location!=-1){
        struct doublyLinkedList * pointer = head;
        for(i=1;i<location;i++){
            pointer = (*head).right;
        }
        i = (*pointer).data;
        (*(*pointer).left).right = (*pointer).right;
        (*(*pointer).right).left = (*pointer).left;
    }
    else{
        i = (*tail).data;
        tail = (*tail).left;
        (*tail).right = 0;

    }
    return i;

}

void printList(){
    struct doublyLinkedList a = *(head);
    while(a.right!=0){
        printf("%d ",a.data);
        a = *(a.right);
    }
    printf("%d ",a.data);
}

int main()
{
    while(1==1){
        int choice;
        printf("\n1. Insert Element at beginning\n2. Insert element at end\n3. Remove element at location i\n4. Remove first element\n5. Remove Last element\n6. Print List\n7. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("\nEnter element: ");
            int i;
            scanf("%d",&i);
            insert(i,0);
        }
        else if(choice==2){
            printf("\nEnter element: ");
            int i;
            scanf("%d",&i);
            insert(i,1);
        }
        else if(choice==3){
            printf("\nEnter i: ");
            int i;
            scanf("%d",&i);
            printf("Removed element: %d\n",del(i));
        }
        else if(choice==4){
            printf("Removed element: %d\n",del(0));
            //enqueue(i);
        }
        else if(choice==5){
            printf("Removed element: %d\n",del(-1));
            //enqueue(i);
        }
        else if(choice==6){
            printList();
        }
        else if(choice==7){
            goto EXIT;
        }
        else printf("\nWrong choice");
    }
EXIT:    return 0;
}



