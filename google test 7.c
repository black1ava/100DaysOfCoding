#include<stdio.h>

int main(){
    int p[] = {39, 13, 20, 21, 40};
    int q[] = {87, 28, 99, 25, 90};
    int n = sizeof(p) / sizeof(*p);
    double line[n][2];
    int k, m = 0, intersect = 0;
    //line : y = ax + b
    for(int i = 0; i < n; i++){
        //line[i][0] is a
        //line[i][1] is b
        if(!((double)(q[i]) - p[i])){
            line[i][0] = 0;
        }else{
            line[i][0] = 1 / ((double)(q[i]) - p[i]);
        }
        line[i][1] = -1 * line[i][0] * p[i];
    }
    float matchPoint[n][2];
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
        //intersect point(x, y):
        //x is matchPoint[m][0]
        //y is matchPoint[m][1]
            if(line[i][0] == line[j][0]){
                matchPoint[m][0] = -9999;
                matchPoint[m][1] = -9999;
                m++;
            }else{
                matchPoint[m][0] = (line[j][1] - line[i][1]) / (line[i][0] - line[j][0]);
                matchPoint[m][1] = (line[i][0] * matchPoint[m][0]) + line[i][1];
                m++;
            }
        }
    }
    for(int i = 0; i < m; i++){
        if(matchPoint[i][1] >= 0 && matchPoint[i][1] <= 1){
            intersect++;
        }
    }
    printf("%d intersection(s)", intersect);
    return 0;
}