#include<stdio.h>
#include<string.h>

int findPerfect(int n, int m);
int findPerfectNum(int n, int m);
int perfect(int n, int m);

int main(){
    int n;
    printf("Input a positive integer: ");
    scanf("%d", &n);
    printf("Perfect number is %d", perfect(n, n));
}

int perfect(int n, int m){

    if(n < 10 && n >= 0){
        return findPerfectNum(n, n);
    }else{
        return findPerfect(n, m);
    }
}

int findPerfectNum(int n, int m){
    char result[50];
    for(int i = 0; i < 10; i++){
        if((n + i) == 10){
            sprintf(result, "%d%d", m, i);
            return atoi(result);
        }
    }
}

int findPerfect(int n, int m){
    char string[50];
    char number[2];
    int length, sum = 0;
    
    sprintf(string, "%d", n);
    length = strlen(string);
    number[1] = '\0';
    
    for(int i = 0; i < length; i++){
        number[0] = string[i];
        sum += atoi(number);
    }
    
    if(sum < 10){
        return findPerfectNum(sum, m);
    }else{
        return findPerfect(sum, m);
    }
}