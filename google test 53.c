#include<stdio.h>

int main(){
    int n[][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
    };
   
    int width = sizeof(*n) / sizeof(**n);
    int height = sizeof(n) / sizeof(*n);
    int turn;
    
    if(width < height){
        turn = 2 * width;
    }else{
        turn = 2 * height - 1;
    }
    
    int reverse, notReverse, limit;
    reverse = 0;
    notReverse = 2;
    limit = 1;
    
    for(int i = 1; i <= turn; i++){
        int mod = i % 4;
        switch(mod){
            case 1:
                for(int j = reverse; j < width - reverse; j++){
                    printf("%d\n", n[reverse][j]);
                }
                break;
            case 2:
                for(int j = limit; j < height - reverse; j++){
                    printf("%d\n", n[j][width - limit]);
                }
                reverse++;
                break;
            case 3:
                for(int j = width - notReverse; j >= limit - 1; j--){
                    printf("%d\n", n[height - limit][j]);
                }
                break;
            case 0:
                for(int j = height - notReverse; j >= limit; j--){
                    printf("%d\n", n[j][limit - 1]);
                }
                limit++;
                notReverse++;
                break;
        }
        
    }
    
    return 0;
}

    