/*

author : yoshki sato
id     : s1270115

*/

#include <stdio.h>
#include <stdlib.h>

void DFS(int);

void rDFS(int);

void transpose(void);

void findSCC();

int n;         // number of vertex ( 'V' of graph G(V,E) )
int label = 0; // the order of vertex visiting
int *visited1;
int *visited2;  // if vertex_i was visited?
int **A;       // Adjacency matrix
int **tA;       //transposed matrix
int tmp=-1; //

int main() {
    int start;
    int i, j;
    /* input number of vertex */
    printf("Input the number of data: ");
    scanf("%d", &n);

    /* memory allocation and initialization */
    visited1 = (int *)malloc(sizeof(int) * n);
    visited2 = (int *)malloc(sizeof(int) * n);
    A = (int **)malloc(sizeof(int *) * n);
    tA = (int **)malloc(sizeof(int *) * n);

    for(i = 0; i < n; i++) {
        A[i] = (int *)malloc(sizeof(int) * n);
        tA[i] = (int *)malloc(sizeof(int) * n);
        visited1[i] = 0;
        visited2[i] = 0;
    }

    printf("Input the Adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
            tA[j][i] = A[i][j];
        }
    }
    /*printf("Input the initial node: 1 to %d\n", n);
    scanf("%d", &start);*/

    findSCC();

   

    /* memory free */
    for(i = 0; i < n; i++){
        free(A[i]);
        free(tA[i]);
    }
    free(A);
    free(tA);
    free(visited1);
    free(visited2);


    return 0;
}

void DFS(int node) {
    int t;

    visited1[node] = ++label;
    for(t = 0; t < n; t++) {
        if(A[node][t] != 0 && visited1[t] == 0) {
            //printf("(%d,%d)\n", node + 1, t + 1);
            DFS(t);
        }
    }
}

void rDFS(int node) {
    int t;

    visited2[node] = ++label;
    for(t = 0; t < n; t++) {
        if(tA[node][t] != 0 && visited2[t] == 0 && visited1[t]) {
            //printf("(%d,%d)\n", node + 1, t + 1);
            if(tmp != node){
                printf("Vertex. %d\n",node + 1);
            }            
            printf("Vertex. %d\n",t + 1);
            tmp = t;
            rDFS(t);
        }
    }
}

void findSCC(){
    int i,k=0;    

    for(i=0;i<n;i++){
        if(!visited1[i]) DFS(i);
    }

    for(i=0;i<n;i++){
        if(!visited2[i]){
            k++;
            printf("Strongly Connected Decomposition (Group %d):\n",k);
            rDFS(i);
            }
    }

}
