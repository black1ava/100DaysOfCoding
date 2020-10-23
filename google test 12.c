#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool compare(char *str1, char *str2, int n);
int map(char *str1, char *str2, int n);

int main(){
    int n , length1, length2, result;
    printf("String length: ");
    scanf("%d", &n);
    char str1[n], str2[n];
    printf("String 1: ");
    scanf("%s", str1);
    printf("String 2: ");
    scanf("%s", str2);
    length1 = strlen(str1);
    length2 = strlen(str2);
    if(length1 != length2)
    //if lengths aren't equal, false
        printf("False");
    else{
    //this function can determine the result
    //false or true
        int result = map(str1, str2, n);
        if(result)
            printf("True");
        else
            printf("False");
    }
    return 0;
}

bool compare(char *str1, char *str2, int n){
    for(int i = 0; i < n; i++){
        int j;
        for(j = 0; j < n; j++){
        //Here if it found a repeated character
        //That repeated character is not itself
            if(i != j && *(str1 + i) == *(str1 + j)){
                break;
            }
        }
        //if the repeated characters map to the same
        //character return false
        if(*(str2 + i) != *(str2 + j)){
            return false;
        }
    }
    return true;
}

int map(char *str1, char *str2, int n){
    int count = 0;
    //if true, increment count
    if(compare(str1, str2, n) && compare(str2, str1, n)){
        count++;
    }
    return count;
}