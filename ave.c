#include<stdio.h>
#include<math.h>

int main(void){
    int i,n=5;
    int j=0;
    double buff[5];
    double ave[5]={0,0,0,0,0};

    for(i=0;i<n*n;i++){
        scanf("%lf ",&buff[i]);
        ave[j]+=buff[i];
        if((i+1)%5 == 0) {
            printf("\n\n%lf\n\n",ave[j]/5);
            j++;
        }
    }
    return 0;
}