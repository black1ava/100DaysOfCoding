#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define NO_INTERSECT INT_MIN

typedef struct node{
    int data;
    struct node *next;
}node;

node *add(node **head, int key){
    node *temp = (node*)malloc(sizeof(node));
    
    temp -> data = key;
    temp -> next = *head;
    *head = temp;
}

int intersect(node *head1, node *head2){
    while(head1 != NULL){
        while(head2 != NULL){
            if(head1 -> data == head2 -> data){
                return head2 -> data;
            }
            head2 = head2 -> next;
        }
        head1 = head1 -> next;
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
        add(&head_1, key_1);
    }
    
    printf("List2: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &key_2);
        add(&head_2, key_2);
    }
    
    if(intersect(head_1, head_2) != NO_INTERSECT){
        printf("%d", intersect(head_1, head_2));
    }else{
        printf("No intersection");
    }
    return 0;
}