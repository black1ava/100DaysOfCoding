#include<stdio.h>

int max(int *arr, int n, int p);
int min(int *arr, int n, int p);
int profit(int *price, int end);

int main(){
    int n;
    printf("How many day: ");
    scanf("%d", &n);
    
    printf("Enter price of stock each day: ");
    
    int stockPrice[n];
    
    for(int i = 0; i < n; i++){
        scanf("%d", &stockPrice[i]);
    }
    printf("Max Profit: $%d", profit(stockPrice, n));
    return 0;
}

int min(int *arr, int n, int p){
    int m = 1000, index;
    for(int i = 0; i < n; i++){
        if(*(arr + i) < m){
            m = *(arr + i);
            index = i;
        }
    }
    return !p ? m : index;
}

int max(int *arr, int n, int p){
    int m = 0, index;
    for(int i = 0; i < n; i++){
        if(*(arr + i) > m){
            m = *(arr + i);
            index = i;
        }
    }
    return !p ? m : index;
}

int profit(int *price, int end){
    int lowPrice = min(price, end, 1);
    int highPrice = max(price, end, 1);
    
    if(lowPrice < highPrice){
        return price[highPrice] - price[lowPrice];
    }
    
    int listProfit[end], goodProfit = 0;
    int highProfit;
    
    for(int i = 0; i < end; i++){
        int count = 0;
        for(int j = i + 1; j < end; j++){
            listProfit[count] = price[j] - price[i];
            count++;
        }
        highProfit = max(listProfit, count, 0);
        if(highProfit > goodProfit){
            goodProfit = highProfit;
        }
    }
    return goodProfit;
}