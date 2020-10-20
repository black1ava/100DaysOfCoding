#include<stdio.h>

int main(){
    int n, *list, multi;
    printf("How many number: ");
    scanf("%d", &n);
    list = (int *)calloc(n + 1, sizeof(int));
    for(int i = 2; i <= n; i++){
        *(list + i) = i;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            multi = i * j;
            if(multi <= n){
                for(int k = 2; k <= n; k++){
                    if(*(list + k) == multi){
                        *(list + k) = 0;
                    }
                }
            }
        }
    }
    for(int i = 2; i <= n; i++){
        if(*(list + i)){
            printf("%d\n", *(list + i));
        }
    }
    free(list);
    return 0;
}