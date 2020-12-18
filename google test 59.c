#include<stdio.h>
#include<string.h>
#include<stdio.h>

int main(){
    char string[12] = "2542540123";
    
    
    int length = strlen(string);
    int size[] = {1, 2, 3};
    int index[5];
    int count = 0;
    
    char temp[10];
    temp[0] = '\0';
    char num[255];
    char ip[4][255];
    
    if(length <= 12){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        if(size[i] + size[j] + size[k] + size[l] == length){
                            index[0] = 0;
                            index[1] = size[i];
                            index[2] = size[j];
                            index[3] = size[k];
                            index[4] = size[l];
                            int n = 0;
                            count = 0;
                            int p = index[0] + index[1];
                            for(int m = 0; m < 4; m++){
                                num[0] = '\0';
                                for(; n < p; n++){
                                    temp[0] = string[n];
                                    strcat(num, temp);
                                }
                                if(num[0] == '0'){
                                    if(strlen(num) <= 1){
                                        strcpy(ip[m], num);
                                        count++;
                                    }
                                }else{
                                    if(atoi(num) <= 255){
                                        strcpy(ip[m], num);
                                        count++;
                                    }
                                }
                                n = p;
                                p += index[m + 2];
                            }
                            if(count == 4){
                                printf("%s.%s.%s.%s\n", ip[0], ip[1], ip[2], ip[3]);
                            }
                        }
                    }
                }
            }
        }
    }else{
        printf("Too long");
    }
    return 0;
}