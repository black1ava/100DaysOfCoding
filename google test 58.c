#include<stdio.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *newNode(int key);
node *insert(node *node, int key);
void showNode(node *node);
void merge(node *node1, node *node2);
node *inorder(node *root);

int main(){
    int k, m, n;
    printf("How many singly linked list: ");
    scanf("%d", &k);
    node *list[k];
    
    node *singlyList;
    
    printf("Size per singly linked List: ");
    scanf("%d", &m);
    printf("Input numbers to each list seperated by space\n");
    for(int i = 0; i < k; i++){
        list[i] = NULL;
        
        printf("List %d : ", i + 1);
        
        for(int j = 0; j < m; j++){
        
            scanf("%d", &n);
            list[i] = insert(list[i], n);
            
        }
    }
    
    for(int i = 0; i < k; i++){
        if(i + 1 < k){
            merge(list[i], list[i + 1]);
        }
    }
    
    singlyList = list[0];
    
    singlyList = inorder(singlyList);
    
    showNode(singlyList);
    return 0;
}

node *newNode(int key){
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp -> data = key;
    
    return temp;
}

node *insert(node *node, int key){
    if(node == NULL){
        node = newNode(key);
        return node;
    }
    
    node -> next = insert(node -> next, key);
    return node;
}

void showNode(node *node){
    if(node != NULL){
        printf("%d ", node -> data);
        showNode(node -> next);
    }
}

void merge(node *node1, node *node2){
    if(node1 -> next == NULL){
        node1 -> next = node2;
        return;
    }
        merge(node1 -> next, node2);
}

node *inorder(node *root){
    
    int temp;
    node *nextNode, *current = root;
    node *order = NULL;
    while(current != NULL){
        nextNode = current -> next;
        while(nextNode != NULL){
            if(current -> data > nextNode -> data){
                temp = current -> data;
                current -> data = nextNode -> data;
                nextNode -> data = temp;
            }
            nextNode = nextNode -> next;
        }
        order = insert(order, current -> data);
        current = current -> next;
    }
    return order;
}