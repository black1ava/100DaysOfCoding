#include<stdio.h>

int main(){
    char nodeName[] = {'A', 'B', 'C', 'D'};
    int node = sizeof(nodeName);
    //end and start node
    char esNode[][2] = {{'A', 'B'}, {'B', 'C'}, {'C', 'D'}, {'D', 'A'}, {'D', 'B'}, {'A', 'C'}};
    int edge = sizeof(esNode) / 2;
    //show original node
    for(int i = 0; i < edge; i++){
        printf("%c -> %c\n", esNode[i][0], esNode[i][1]);
    }
    printf("Reverse\n");
    //use matrix adjacency
    int matrix[node][node];
    int reverse[node][node];
    //set 0 to matrix
    for(int i = 0; i < node; i++){
        for(int j = 0; j < node; j++){
            matrix[i][j] = 0;
        }
    }
    /*looks like this
    A B C D
  A 0 0 0 0
  B 0 0 0 0
  C 0 0 0 0
  D 0 0 0 0
    */
    char start, end;
    int startInd, endInd, ind;
    //find pairs of end and start node
    for(int i = 0; i < edge; i++){
        start = esNode[i][0];
        end = esNode[i][1];
        for(int j = 0; j < node; j++){
            if(nodeName[j] == start){
                startInd = j;
            }
            if(nodeName[j] == end){
                endInd = j;
            }
        }
        //set the intersection coordinate to 1
        matrix[startInd][endInd] = 1;
    }
    /*
    A B C D
  A 0 1 1 0
  B 0 0 1 0
  C 0 0 0 1
  D 1 1 0 0
    */
    for(int i = 0; i < node; i++){//reverse it
        for(int j = 0; j < node; j++){
            reverse[i][j] = matrix[j][i];
        }
    }
    /*
    A B C D
  A 0 0 0 1
  B 1 0 0 1
  C 1 1 0 0
  D 0 0 1 0
  
    */
    for(int i = 0; i < node; i++){
        for(int j = 0; j < node; j++){
            if(reverse[i][j] == 1){
                printf("%c -> %c\n", nodeName[i], nodeName[j]);
            }
        }
    }
    return 0;
}