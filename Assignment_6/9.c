#include <stdio.h>

struct Node{
    int visited;
    int data;
    struct Node * next;
};

struct Node * head = 0;
struct Node * tail = 0;

void insert(int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->visited = 0;
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

int checkCycle(){
    struct Node * ptr = head;
    while(ptr->next!=0){
        if(ptr->visited==1) return 1;
        ptr->visited = 1;
        ptr = ptr->next;
    }
    return 0;
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
    printf("Answer: %d",checkCycle());
    return 0;
}

