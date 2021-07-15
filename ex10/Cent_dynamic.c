#include <stdio.h>
#include <stdlib.h>

#define INFTY 99999
#define PAY 183 //支払い額マクロ

int main(){
    int i,j;
    int cent[5]={1,5,10,17,25};
    int payment=183;
    int dp[PAY+2]; //金額iを支払うための最小硬貨枚数

    for( i=0; i<payment+2; i++){
        dp[i] = INFTY;
    }
    dp[0] = 0;

    for( j=0; j<payment; j++){
        for( i=0; i<5; i++){
            /* dp[j+cent[i]] : 以前に算出したj+cent[i]を支払う暫定枚数
               dp[j]+1 : j円払う時の支払い枚数にcent[i]円を1枚プラスした枚数*/
            if(dp[j+cent[i]] > dp[j]){
                dp[j+cent[i]] = dp[j]+1;
            }
        }
    }

    printf("Minimum number of cents used to pay 183cents is %d.\n",dp[payment]);

    return 0;
}