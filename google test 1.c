//Google test 1
#include<stdio.h>

int main(){
    int n, *input, k, count, com;
    count = 0;
    printf("Numbers of list: ");
    scanf("%d", &n);
    input = (int *)calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        printf("Number %d: ", i + 1);
        scanf("%d", &*(input + i));  
    }
    printf("Input a number k: ");
    scanf("%d", &k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && i > j){
                if(*(input + i) + *(input + j) == k){
                    printf("%d + %d = %d\n", *(input + i), *(input + j), k);
                    break;
                }else{
                    count++;
                }
            }
        }
    }
    n--;
    com = n * (n + 1) / 2;
    if(count == com){
        printf("False");
    }else{
        printf("True");
    }
    free(input);
    return 0;
}