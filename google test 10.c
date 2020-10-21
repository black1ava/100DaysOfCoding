#include<stdio.h>

int small(int a, int b){
    return a < b ? a : b;
}

int minimum(int *arr, int n){
    int min = 999999;
    for(int i = 0; i < n; i++){
        min = small(min, *(arr + i));
    }
    return min;
}

int main(){
    int n;
    printf("How many number: ");
    scanf("%d", &n);
    int num[n], res;
    for(int i = 0; i < n; i++){
        printf("Number %d: ", i + 1);
        scanf("%d", &num[i]);
    }
    res = minimum(num, n);
    printf("Answer is %d", res);
    return 0;
}