#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define INFTY 99999

 //計算回数

int main(){
    int n,b,a_sum=0;
    int i,j,cnt;
    int flag=0;
    int *dp,*a;

    //printf("Input number & Positive Integer ->");
    scanf("%d %d",&n,&b);

    //printf("Input positive integers ->");

    
    dp = (int *)malloc(sizeof(int)* b+1);
    a = (int *)malloc(sizeof(int)* n);

    for(i=0;i<=b;i++){
        dp[i]=0;
    }


    for( i=0; i<n; i++){
        scanf("%d",&a[i]);
        dp[a[i]]=1;
    }

    for( i=0; i<=b; i++){
        for( j=0; j<=b; j++){
            if(i == a[j]) dp[i] = 1;
        }
        if(i == 0){
            dp[i] = 0;
            continue;
        }
        if(dp[i] == 1) continue;
        dp[i] = INFTY;
    }
    dp[0] = 0;

    for( j=0; j<=b; j++){
        for( i=0; i<n; i++){
            if(j+a[i] == b) flag=1;
            if(dp[j+a[i]] > dp[j]){
                dp[j+a[i]]= dp[j]+1;
            }
        }
        if(flag == 1) break;
    }

    cnt = dp[b];
    if(dp[b] != INFTY){
        printf("YES\n");
        for( i=0; i<n; i++){
            if(dp[b-a[i]] < cnt){
                printf("%d ",a[i]);
                cnt--;
                a_sum += a[i];
                if(cnt == 1){
                    printf("%d\n",b-a_sum);
                    cnt--;
                }
            }
        }
    }else{
        printf("NO\n");
    }

    printf("%d\n",dp[b]);

    return 0;
}