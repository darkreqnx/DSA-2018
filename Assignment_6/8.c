#include <stdio.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * head = 0;
struct Node * tail = 0;

void insert(int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = 0;
    if(tail!=0) tail->next = ptr;
    tail = ptr;
    if(head==0) head = ptr;
}

void printList(){
    struct Node * a = head;
    while(a->next!=0){
        printf("%d ",a->data);
        a = a->next;
    }
    printf("%d ",a->data);

}

struct Node * pairSwap(struct Node * ptr){
    if(ptr!=0 && ptr->next!=0){
        struct Node * returning = ptr->next;
        struct Node * next = ptr->next->next;
        ptr->next->next = ptr;
        ptr->next = pairSwap(next);
        return returning;
    }
    else{
        return ptr;
    }

}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        int data;
        scanf("%d",&data);
        insert(data);
    }
    printf("\nOriginal List:\n");
    printList();
    head = pairSwap(head);
    printf("\nAfter swap:\n");
    printList();
    return 0;
}

