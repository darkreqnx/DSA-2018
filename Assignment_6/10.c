#include <stdio.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * head = 0;
struct Node * tail = 0;

struct Node * insert(int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = 0;
    if(tail!=0) tail->next = ptr;
    tail = ptr;
    if(head==0) head = ptr;
    return ptr;
}

void printList(){
    struct Node * a = head;
    while(a->next!=0){
        printf("%d ",a->data);
        a = a->next;
    }
    printf("%d ",a->data);

}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    struct Node * array[m];
    int i;
    for(i=0;i<n;i++){
        struct Node * ptr = insert(i);
        if(i>=m){
            array[i%m]->next = ptr;
        }
        array[i%m] = ptr;
    }
    struct Node * ptr = head;
    while(ptr->next!=0){
        ptr = ptr->next;
    }
    printf("Answer: %d",ptr->data);
    return 0;
}

