/*

author : yoshiki sato
id     : s1270115


必要に応じてコードを追加すること。
*/

#include <stdio.h>
#include <stdlib.h>
#define INFTY 99999

#define min(a,b) ( (a)<(b) ? (a) : (b))
#define max(a,b) ( (a)>(b) ? (a) : (b))

int Maggs_Plotkin(int, int, int);
void MST_view(int **D0, int **, int);

int main() {
    int i, j, k;
    int **Data_orginal, **Data_edited, n;

    /* input data (size) */
    printf("Input the number of data: ");
    scanf("%d", &n);
    /* Generate arrays (memory allocation)*/
    Data_orginal = (int **)malloc(n * sizeof(int *));
    Data_edited = (int **)malloc(n * sizeof(int *));

    for(i = 0; i < n; i++) {
        Data_orginal[i] = (int *)malloc(n * sizeof(int));
        Data_edited[i] = (int *)malloc(n * sizeof(int));
    }

    /* input data (matrix)*/
    printf("Input the Adjacency or Distance matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &Data_orginal[i][j]);
        }
    }

    /* Main routines */
     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++)  Data_edited[i][j] = Maggs_Plotkin(Data_orginal[i][j], Data_orginal[i][k], Data_orginal[k][j]);
        }
    }
    
    // end 3-level nested loop

    
    MST_view(Data_orginal,Data_edited,n);

    /* free allocated memory*/
    for(i = 0; i < n; i++) {
        free(Data_orginal[i]);
        free(Data_edited[i]);
    }

    free(Data_orginal);
    free(Data_edited);

    return 0;
}

int Maggs_Plotkin(int D_ij, int D_ik, int D_kj) {
    int Dk_ij;

    Dk_ij = min(D_ij, max(D_ik, D_kj));

    return Dk_ij;
}

// D0[][] -> 元の2次元配列。つまり隣接行列A
// Dn[][] -> アルゴリズムで処理された2次元配列。つまりA^k
// n -> グラフの頂点数|V|
void MST_view(int **D0, int **Dn, int n) {
    int i, j;
    int costs = 0;

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) { // A上で辺があったところが、A^kの全域木に採用されているなら重みを加える
            if(D0[i][j] == Dn[i][j] && D0[i][j] != INFTY) {
                costs += Dn[i][j];
                printf("%d\n", Dn[i][j]);
            }
        }
    }

    printf("MST total weights:%d\n", costs);
}
/*
    詳しくはMaggsとPlotkinの論文を参考
    http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.52.3823&rep=rep1&type=pdf
*/