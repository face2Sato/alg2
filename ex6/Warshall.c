/*

author : Yoshiki Sato   
id     : s1270115

*/


#include <stdio.h>
#include <stdlib.h>

#define INFTY 99999

int Warshall(int, int, int);

int main() {
    int i, j, k;
    int sum;

    int **Data, n;
    int **d;

    /* input data (size) */
    printf("Input the number of data: ");
    scanf("%d", &n);

    /* Generate arrays (memory allocation)*/
    Data = (int **)malloc(n * sizeof(int *));
    d = (int **)malloc(n * sizeof(int *));

    for(i = 0; i < n; i++) {
        Data[i] = (int *)malloc(n * sizeof(int));
        d[i] = (int *)malloc(n * sizeof(int));
    }

    // 初期化
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            d[i][j] = INFTY;
        }
    }
    /* input data (matrix)*/
    printf("Input the Adjacency or Distance matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &Data[i][j]);
        }
    }

    /* Main routines */

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++)  Data[i][j] = Warshall(Data[i][j], Data[i][k], Data[k][j]); // Warshall's Algorithm

        }
    }
    // end 3-level nested loop

    for(i=0;i<n;i++){
        sum=0;
        for(j=0;j<n;j++){
            sum+=Data[j][i];
            //printf("%d ",Data[i][j]);
        }
        if(!sum) printf("Vertex %d cannot be reached from any other vertex.\n",i);
        //printf("\n");
    }

    /* free allocated memory*/
    for(i = 0; i < n; i++) {
        free(Data[i]);
        free(d[i]);
    }
    free(Data);
    free(d);

    return 0;
}

/* Kernel process of Floyd's & Warshall's Algorithm */

int Warshall(int A_ij, int A_ik, int A_kj) {
    /* Arguments A_ij, A_ik, A_kj means A^{k-1}[i][j], A^{k-1}[i][k],A^{k-1}[k][j] at the pseudo code. */
    int Ak_ij; /* A^k[i][j] */

    Ak_ij = ((A_ij + (A_ik * A_kj > 0))? 1 : 0);

    return Ak_ij;
}
