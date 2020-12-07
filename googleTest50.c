#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char characters[][4] = {"FACI", "OBQP", "ANOB", "MASS"};
    char targetWord[] = "FOAM";
    int length, area;
    
    length = sizeof(characters) / sizeof(*characters);
    area = sizeof(characters) / sizeof(**characters);
    
    char *leftToRight, *upToDown, assistant;
    leftToRight = malloc(area);
    upToDown = malloc(area);
    
    int correct = 0;
    
    for(int i = 0, k = 0; i < length, k < 2; i++, k++){
    
        leftToRight[0] = '\0';
        upToDown[0] = '\0';
        
        for(int j = 0; j < 4; j++){
        
            strncat(leftToRight, &characters[i][j], 1);
            strncat(upToDown, &characters[j][i], 1);
            
        }
        
        if(!(strcmp(leftToRight, targetWord) && strcmp(upToDown, targetWord))){
            correct++;
            
        }
    }
    
    if(correct){
        printf("True");
    }else{
        printf("False");
    }
    
    free(leftToRight);
    free(upToDown);
    
    return 0;
}