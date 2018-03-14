#include <stdio.h>

struct Node{
    struct Node * prev;
    int data;
    struct Node * next;
};

struct Node * head = 0;
struct Node * tail = 0;

void insert(int data,int location){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    if(location==0){
        ptr->next = head;
        if(head!=0) head->prev = ptr;
        else tail = ptr;
        ptr->prev = 0;
        head = ptr;
    }
    if(location==1){
        ptr->prev = tail;
        if(tail!=0) tail->next = ptr;
        else head = ptr;
        ptr->next = 0;
        tail = ptr;
    }
    printf("\nInsertion Done!\n");
}

int del(int location){
    if(head!=0){
        struct Node * a = head;
        int i;
        for(i=0;i<location;i++){
            a = a->next;
        }
        int data = a->data;
        if(a->prev != 0) a->prev->next = a->next;
        if(a->next != 0) a->next->prev = a->prev;
        if(head==tail){
            head = 0;
            tail = 0;
        }
        return data;
    }
    else return -1;
}

void printList(){
    struct Node * a = head;
    while(a->next!=0){
        printf("%d ",a->data);
        a = a->next;
    }
    printf("%d ",a->data);

}


int six(){

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
