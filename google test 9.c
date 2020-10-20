#include<stdio.h>

int subArray(int *arr, int n);

int main(){
    int arr[] = {1, 2, 3, 1, 5, 4, 5};
    int n, output;
    n = sizeof(arr) / sizeof(*arr);
    output = subArray(arr, n);
    printf("Length is %d", output);
    return 0;
}

int subArray(int *arr, int n){
    int result = 0;
    for(int i = 0; i < n; i++){
        int j;
        for(j = 0; j < n; j++){
            if(*(arr + i) == *(arr + j)){
                break;
            }
        }
        if(i == j){
            result++;
        }
    }
    return result;
}