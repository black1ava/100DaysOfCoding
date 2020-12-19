#include<stdio.h>

int ascend(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int findIndex(int list[], int length, int num){
    int i;
    for(i = 0; i < length; i++){
        if(list[i] == num){
            break;
        }
    }
    return i;
}

void cpy(int list1[], int list2[], int length){
    for(int i = 0; i < length; i++){
        list2[i] = list1[i];
    }
}

int longestSubLength(int list1[], int list2[], int length){
    int currentIndex = findIndex(list1, length, list2[0]);
    int lastIndex = 0;
    int current = list2[0];
    int count = 0;
    
    for(int i = 1; i < length; i++){
        int index = findIndex(list1, length, list2[i]);
        
        if(index > currentIndex){
        
            count++;
            lastIndex = currentIndex;
            currentIndex = index;
            
        }else if(index >= lastIndex && index < currentIndex){
        
            currentIndex = index;
            
        }
    }
    
    return count + 1;
}

int main(){
    int n;
    printf("Length of the array: ");
    scanf("%d", &n);
    
    int list[n];
    
    printf("Enter all numbers in one line seperate by space: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &list[i]);
    }
    
    int cpyList[n];
    
    cpy(list, cpyList, n);
    qsort(cpyList, n, sizeof(int), ascend);
    
    printf("Longest increasing subsequence: %d", longestSubLength(list, cpyList, n));
    
    return 0;
}