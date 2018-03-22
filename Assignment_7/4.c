#include <stdio.h>

struct Node{
    int data;
    struct Node * small;
    struct Node * large;

};

struct Node * head = NULL;
struct Node * tail = NULL;
struct Node * previous = NULL;

void convertTreeToList(struct Node * ptr){
    if(ptr->small!=NULL){
        convertTreeToList(ptr->small);
    }
    else{
        if(head==NULL) head = ptr;
    }
    if(previous!=NULL){
        previous->large = ptr;
        ptr->small = previous;
    }
    previous = ptr;
    if(ptr->large!=NULL){
        convertTreeToList(ptr->large);
    }
}

int main(){
    //HardCoded Tree
    struct Node a,b,c,d,e,f,g;
    a.data = 0;b.data = 1;c.data = 2;d.data = 3;e.data = 4;f.data = 5;g.data = 6;
    a.small = &b;a.large = &c;b.small = &d;b.large = &e;e.small = &f;e.large = &g;
    c.small=NULL;c.large=NULL;d.small=NULL;d.large=NULL;f.small=NULL;f.large=NULL;g.small=NULL;g.large=NULL;
    //Main Code
    convertTreeToList(&a);
    tail = previous;
    tail->large = head;
    head->small = tail;

    //Testing
    struct Node * current = head;
    while(current!=tail){
        printf("\n");
        printf("Data: %d\nPointer: %d\nSmall: %d\nLarge: %d\n",current->data,current,current->small,current->large);
        current = current->large;
    }
    printf("\nData: %d\nPointer: %d\nSmall: %d\nLarge: %d\n",current->data,current,current->small,current->large);
    return 0;
}
