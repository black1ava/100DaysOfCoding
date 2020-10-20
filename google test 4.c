#include<stdio.h>

void swap(int *arr, int *pair, int n, int count);

int main(){
    int n, count;
    //arrange randomly
    int ran[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    //this how pairs looks like
    int pair[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    n = sizeof(ran) / sizeof(*ran);
    for(int i = 0; i < n; i++){
        printf("%d ", ran[i]);
    }
    printf("\n\n");
    if(n % 2){
        printf("No pair"); //if n is an odd number
                          //it has no pair
    }else{
        //this function can arrange each number
       //to be paired and swap times
        swap(ran, pair, n, count);
    }
    return 0;
}

void swap(int *arr, int *pair, int n, int count){
    int noPair, found, change;
    count = 0;
    for(int i = 0; i < n; i++){
        //if number is not in correct place as "pair"
        if(arr[i] != pair[i]){
            noPair = pair[i];
            for(int j = i + 1; j < n; j++){
                if(arr[j] == noPair){
                    //found where its pair is
                    found = j;
                }
            }
            //and start swapping
            change = arr[i];
            arr[i] = arr[found];
            arr[found] = change;
            //increment count to know how many times
           //numbers have swapped
            count++; 
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\nswap: %d times", count);
}