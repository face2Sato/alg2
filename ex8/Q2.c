#include<stdio.h>

int main(void){
    int j,i=0,coin_total=0;
    int coin[4]={25,10,5,1};
    int coin_cnt[4]={0,0,0,0};
    int N,coin_num[4];
    int paid;

    printf("Input numbers of each cent(coin).\n->");
    scanf("%d %d %d %d",&coin_num[0],&coin_num[1],&coin_num[2],&coin_num[3]);
    
    printf("Input how many cents should you pay?\n->");
    scanf("%d",&N);

    paid = N;

    while(1){
        while(paid < coin[i] && i<4) i++;

        if(paid-coin[i]<0 || coin_num[i]<0) break;
        paid-=coin[i];
        coin_cnt[i]++;
        coin_num[i]--;
    }

    if(paid!=0){
        printf("Error: you cannot pay for this value.");
        return 0;
    }

    for(i=0;i<4;i++){
        printf("[%dcent] %d used \n",coin[i],coin_cnt[i]);
        coin_total+=coin_cnt[i];
    }

    printf("Totally, you used %d coins for %d cents\n",coin_total,N);

    return 0;
}