#include<stdio.h>

int main(){
    int arr[] = {1, 2, 3, 4};
    int n, swap;
    n = sizeof(arr) / sizeof(*arr);
    for(int i = 0; i < n; i += 2){
        swap = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = swap;
    }
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            printf("%d", arr[i]);
        }else{
            printf("%d -> ", arr[i]);
        }
    }
    return 0;
}