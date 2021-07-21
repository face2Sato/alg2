#include <stdio.h>
#include <math.h>

#define N 10
#define MASK (int)pow(2,10)-1
//バイナリで(11 1111 1111)となるマスクを生成。l17で用いる。
    
int  COUNT;
//s1270115なので、(5,1)に穴を開ける
int y=1;
int x=5;

void Backtrack(int row, int left, int down, int right)
{
    int  bitmap, bit;

    if (row == N) {
        COUNT++;          // 10個クイーンを置けたので解の個数をカウントする
    } else {
        bitmap = MASK & ~(left | down | right); //bitmapにおいて、1...配置可,0...配置不可
        if(row==y) bitmap = bitmap & ~(1 << (N-x-1)); //(1<<(N-x-1)は今回(000010000)になり、これの反転ビットとANDを取ればよい

        while (bitmap) { //配置できる場所がある間ループ(全てのビットが0になるとfalseになる仕組み)

            // 最も下位の１ビットを抽出　ex...1010(オリジナルのビット列) and 0110(2の補数) = 0010)
            // bitは、今回クイーンを置く位置を1として示すために用いる
            bit = -bitmap & bitmap;       
            bitmap ^= bit; //XOR
        
            //row+1...次の列を指す 
            //(left|bit)<<1...bitの斜め左下を配置不可にする
            //down|bit...bitの真下を配置不可にする
            //(right|bit)>>1...bitの斜め右下を配置不可にする
            //上から順に探索するのでこれでOK.
            Backtrack(row+1, (left | bit)<<1, down | bit, (right | bit)>>1);
        }
    }
}
void main(){
    COUNT = 0;     /* 解の個数:初期化 */
    Backtrack(0, 0, 0, 0);
    printf("解: %d個\n", COUNT);
}