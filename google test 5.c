#include<stdio.h>
#include<string.h>

#define time 100

char *rearrange(char *string, int n);
void finalize(char *string, int n, int attempt);
void check(char *string, int n, int *count);
void reverse(char *string, int n);

int main(){
    char string[] = "ababccbaa";
    int n = strlen(string);
    finalize(string, n, time);
    return 0;
}

char *rearrange(char *string, int n){
    int loc;
    char change, alpha;
    for(int i = 0; i < n; i++){
        if(*(string + i) == *(string + i + 1)){
            alpha = *(string + i);
            for(int j = i; j < n; j++){
                if(*(string + j) != alpha){
                    loc = j;
                    break;
                }
            }
            change = *(string + i + 1);
            *(string + i + 1) = *(string + loc);
            *(string + loc) = change;
        }
    }
    return string;
}

void finalize(char *string, int n, int attempt){
    int count;
    char test[n];
    strcpy(test, rearrange(string, n));
    check(test, n, &count);
    if(attempt == 0){
        puts("None");
    }else{
        if(!count){
            puts(test);
        }else{
            reverse(test, n);
            finalize(test, n, attempt - 1);
        }
    }
}

void check(char *string, int n, int *count){
    *count = 0;
    for(int i = 0; i < n; i++){
        if(*(string + i) == *(string + i + 1)){
            (*count)++;
        }
    }
}

void reverse(char *string, int n){
    char str[n];
    strcpy(str, string);
    for(int i = 0, j = n - 1; i < n, j >= 0; i++, j--){
        *(string + i) = *(str + j);
    }
}