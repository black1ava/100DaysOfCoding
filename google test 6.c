#include<stdio.h>

int min(int a, int b);
int minimum(int *arr, int n);

int main(){
    int num[3][2]= {{7, 9}, {2, 4}, {5, 8}};
    int overlap[3], zero = 0;
    for(int i = 0; i < 3; i++){
        overlap[i] = num[i][1] - num[i][0] - 1;
    }
    for(int i = 0; i < 3; i++){
        if(!overlap[i]){
            zero++;
        }
    }
    if(zero){
        puts("overlap");
    }else{
        printf("%d", minimum(overlap, 3));
    }
    return 0;
}

int min(int a, int b){
    return a < b ? a : b;
}

int minimum(int *arr, int n){
    int max = 100;
    for(int i = 0; i < n; i++){
        max = min(max, arr[i]);
    }
    return max;
}