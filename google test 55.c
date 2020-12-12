#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void getList(int *list, int n);
int *squareOrder(int *list, int n);

int main(){
    int n, *list;
    printf("How many number: ");
    scanf("%d", &n);
    list = (int*)calloc(n, sizeof(int));
    getList(list, n);
    list = squareOrder(list, n);
    
    for(int i = 0; i < n; i++){
        printf("%d ", *(list + i));
    }
    
    free(list);
    return 0;
}

void getList(int *list, int n){
    for(int i = 0; i < n; i++){
        printf("Number %d: ", i + 1);
        scanf("%d", &*(list + i));
    }
}

int *squareOrder(int *list, int n){
    for(int i = 0; i < n; i++){
        *(list + i) = pow(*(list + i), 2);
    }
    
    int temp;
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(*(list + i) > *(list + j)){
                temp = *(list + i);
                *(list + i) = *(list + j);
                *(list + j) = temp;
            }
        }
    }
    
    return list;
}