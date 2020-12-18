#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool check(char *string, int n){
    char open[] = "({[";
    char close[] = ")}]";
    int indexOpen[3], indexClose[3];
    int match = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            if(string[i] == open[j]){
                if(string[n - i - 1] == close[j]){
                    continue;
                }else{
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    char input[100];
    
    printf("Enter open curve, square and curly bracket: ");
    
    scanf("%s", input);
    
    int length = strlen(input);
    char *string = malloc(length);
    strcpy(string, input);
    
    if(check(string, length)){
        printf("true");
    }else{
        printf("false");
    }
    
    return 0;
}
