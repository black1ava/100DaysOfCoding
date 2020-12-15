#include<stdio.h>

typedef struct{
    int start, end;
}interval;

void mergeInterval(interval intervals[], int size);

int main(){
    interval intervals[] = {{1, 3}, {5, 8}, {4, 10}, {20, 25}};
    
    int size = sizeof(intervals) / sizeof(intervals[0]);
    
    mergeInterval(intervals, size);
    return 0;
}

void mergeInterval(interval intervals[], int size){
    
    int start, end;
    
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
        
            if(intervals[i].end >= intervals[j].start){
            
                if(intervals[i].end <= intervals[j].end){
                    end = intervals[j].end;
                }else{
            
                    end = intervals[i].end;
                }
            
                if(intervals[i].start <= intervals[j].start){
                    start = intervals[i].start;
                }else{
                    start = intervals[j].start;
                }
            
                intervals[i] = (interval) {start, end};
                intervals[j] = intervals[j + 1];
            
                size--;
                i--;
            }
        }
    }
    
    for(int i = 0; i < size; i++){
        printf("(%d, %d), ", intervals[i].start, intervals[i].end);
    }
}
