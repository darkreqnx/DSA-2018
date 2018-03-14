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

void reverse1(){
    struct Node * a = head;
    struct Node * prev = head;
    struct Node * next = a->next;
    while(a!=tail){
        a = next;
        if(a!=tail) next = a->next;
        a->next = prev;
        prev = a;
    }
    head->next = 0;
    tail = head;
    head = a;
}

void reverse2(struct Node * ptr){
    if(ptr==tail) head = tail;
    else{
        reverse2(ptr->next);
        ptr->next->next = ptr;
        ptr->next = 0;
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
    reverse1();
    printf("\nAfter reverse 1:\n");
    printList();
    reverse2(head);
    printf("\nAfter reverse 2:\n");
    printList();
    return 0;
}
