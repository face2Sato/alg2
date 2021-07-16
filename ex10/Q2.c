#include<stdio.h>

#define MAX 500

int dp[MAX];
int a[MAX];
int b,n;

void main(){
    int i,j,flg=0;

    scanf("%d %d",&n,&b);

    for(i=0;i<n;i++)    scanf("%d",&a[i]);

    for(i=0;i<=b;i++)    dp[i]=-1;

    dp[0]=0;


    for(i=0;i<n;i++){
        if(flg) break;
        
        for(j=b;j>=0;j--){
            if(dp[j]!=-1 && dp[j]+a[i]<=b) dp[j+a[i]]=a[i]; 
            if(dp[b]!=-1){ 
                flg=1;
                break;
            }
        }
    }

    // for(i=0;i<=b;i++) {
    //     if(i%20==0) printf("\n");
    //     printf("%d ",dp[i]);
    // }

    // printf("\n\n\n");
    
    if(flg) printf("YES\n");
    else{
        printf("NO\n");
        return;
    }

    i=b;

    while(dp[i]!=dp[0]){
        printf("%d ",dp[i]);
        i-=dp[i];
    }

    printf("\n");
}