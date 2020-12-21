#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct runLength{
    int num;
    char alpha;
    struct runLength *next;
} runLength;

runLength *master = NULL;

runLength *add(int k, char c){
    runLength *temp = (runLength*)malloc(sizeof(runLength));
    
    temp -> num = k;
    temp -> alpha = c;
    temp -> next = master;
    return temp;
}

void show(runLength* head){
    if(head != NULL){
        show(head -> next);
        printf("%d%c", head -> num, head -> alpha);
    }
}

int main(){
    char string[100];
    printf("Enter a repeated string: ");
    scanf("%s", string);
    
    int length = strlen(string);
    int count = 1;
    runLength *alphas = NULL;
    
    for(int i = 1; i <= length; i++){
        if(string[i] == string[i - 1]){
            count++;
        }else{
            alphas = add(count, string[i - 1]);
            master = alphas;
            count = 1;
        }
    }
    show(master);
    return 0;
}
