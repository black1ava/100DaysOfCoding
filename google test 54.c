#include<stdio.h>

int main(){
    int n, k;
    printf("How many number: ");
    scanf("%d", &n);
    
    int *list;
    list = (int*)calloc(n, sizeof(int));
    
    for(int i = 0; i < n; i++){
        printf("Number %d: ", i + 1);
        scanf("%d", &*(list + i));
    }
    
    printf("Number k: ");
    scanf("%d", &k);
    
    int *newList;
    newList = (int*)calloc(n, sizeof(int));
    int index = 0;
    
    for(int i = 0; i < n; i++){
        if(*(list + i) < k){
            *(newList + index) = *(list + i);
            index++;
        }
    }
    
    for(int i = 0; i < n; i++){
        if(*(list + i) >= k){
           *(newList + index) = *(list + i);
            index++;
        }
    }
    
    
    for(int i = 0; i < n; i++){
        printf("%d ", *(newList + i));
    }
    free(list);
    free(newList);
    return 0;
}