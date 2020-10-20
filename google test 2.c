#include<stdio.h>
#include<stdbool.h>

typedef struct par{
    int valu;
    struct par *left, *right;
}par;

par *parents(int num);
int output(par *input);
void check(par *input, int *count);
bool child(par *input);
bool sib(par *input, int hint);

int main(){
/*
          0
         / \
        1   0
           / \
          1   0
         / \
        1   1
*/
    par *input;
    input = parents(0);
    input -> left = parents(1);
    input -> right = parents(0);
    input -> right -> left = parents(1);
    input -> right -> right = parents(0);
    input -> right -> left -> left = parents(1);
    input -> right -> left -> right = parents(1);
    printf("%d", output(input));
    return 0;
}

par *parents(int num){
    par *pos = (par *)malloc(sizeof(par));
    pos -> left;
    pos -> right;
    pos -> valu = num;
    return pos;
}

int output(par *input){
    int count = 0;
    check(input, &count);
    return count;
}

void check(par *input, int *count){
    if(input == NULL){
        return;
    }
    if(child(input)){
        (*count)++;
    }
    check(input -> left, count);
    check(input -> right, count);
}

bool child(par *input){
    if(input == NULL){
        return true;
    }
    int hint = input -> valu;
    return sib(input, hint);
}

bool sib(par *input, int hint){
    if(input == NULL){
        return true;
    }
    return ((input -> valu == hint) && sib(input -> left, hint) && sib(input -> right, hint));
}