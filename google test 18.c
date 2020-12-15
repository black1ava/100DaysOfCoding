#include<stdio.h>

void allOne(int *arr, int size);
void findMajor(int *arr, int size);

int main(){
    int lst[] = {1, 2, 1, 1, 3, 1, 0, 1,};
    
    int n = sizeof(lst) / sizeof(lst[0]);
    
    findMajor(lst, n);
    
    return 0;
}

void allOne(int *arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = 1;
    }
}

void findMajor(int *arr, int size){
    int num[size];
    allOne(num, size);
    int i;
    for(i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] == arr[j]){
                num[i]++;
            }
        }
        if(num[i] > size / 2){
            break;
        }
    }
    if(i == size){
        printf("No Major");
    }else{
        printf("%d", arr[i]);
    }
}