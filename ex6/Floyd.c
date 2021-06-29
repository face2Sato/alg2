/*

author : yoshiki sato   
id     : s1270115

*/


#include <stdio.h>
#include <stdlib.h>

#define INFTY 99999

#define min(a,b) ( (a)<(b) ? (a) : (b))

int Floyd(int, int, int);

int main() {
    int i, j, k;
    int vmin1,vmin2,vmax1,vmax2;
    int max=0;
    int min=INFTY;
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
            for(k=0;k<n;k++)  Data[i][j] = Floyd(Data[i][j], Data[i][k], Data[k][j]); // Floyd's Algorithm
        }
    }
    // end 3-level nested loop

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(min > Data[i][j]){
                min = Data[i][j];
                vmin1 = i;
                vmin2 = j;
            }

            if(max < Data[i][j] && Data[i][j] != INFTY){
                max = Data[i][j];
                vmax1 = i;
                vmax2 = j;
            }
        }
    }

    printf("Min: d(%d, %d) = %d\n",vmin1,vmin2,min);
    printf("Max: d(%d, %d) = %d\n",vmax1,vmax2,max);
    printf("d(%d, %d) = %d\n",vmin1,vmax1,Data[vmin1][vmax1]);
    printf("d(%d, %d) = %d\n",vmin2,vmax2,Data[vmin2][vmax2]);
    /* free allocated memory*/
    for(i = 0; i < n; i++) {
        free(Data[i]);
        free(d[i]);
    }
    free(Data);
    free(d);

    return 0;
}

int Floyd(int D_ij, int D_ik, int D_kj) {
    /* Arguments D_ij, D_ik, D_kj means D^{k-1}[i][j], D^{k-1}[i][k],D^{k-1}[k][j] at the pseudo code. */
    int Dk_ij; /* D^k[i][j] */

    Dk_ij = min(D_ij, D_ik + D_kj);

    return Dk_ij;
}
