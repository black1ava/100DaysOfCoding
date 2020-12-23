#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

#define NO_INTERSECT INT_MIN

typedef struct node{
    int data;
    struct node *next;
}node;

node *head = NULL;

node *add(node *master, int key){
    node *temp = (node*)malloc(sizeof(node));
    
    temp -> data = key;
    temp -> next = master;
    master = temp;
    return master;
}

node *addHead(int k){
    node *temp = (node*)malloc(sizeof(node));
    temp -> data = k;
    temp -> next = NULL;
    return temp;
}

node *addToHead(node *node, int k){
    if(node == NULL){
        node = addHead(k);
        return node;
    }
    node -> next = addToHead(node -> next, k);
    return node;
}

int intersect(node *head1, node *head2){
    while(head1 != NULL){
        head = addToHead(head, head1 -> data);
        head1 = head1 -> next;
    }
    while(head2 != NULL){
        if(head2 -> data == head -> data){
            return head2 -> data;
        }
        head2 = head2 -> next;
        head = head -> next;
    }
    return NO_INTERSECT;
}

void showNode(node *head){
    while(head != NULL){
        printf("%d ", head -> data);
        head = head -> next;
    }
}

int main(){
    int n, key_1, key_2;
    
    printf("How many number: ");
    scanf("%d", &n);
    
    node *head_1 = NULL;
    node *head_2 = NULL;
    
    printf("List1: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &key_1);
        head_1 = add(head_1, key_1);
    }
    
    printf("List2: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &key_2);
        head_2 = add(head_2, key_2);
    }
    
    int result = intersect(head_1, head_2);
    
    if(result != NO_INTERSECT){
        printf("%d", result);
    }else{
        printf("No Intersection");
    }
    
    return 0;
}
