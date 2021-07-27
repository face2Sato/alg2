/*

author : yoshiki sato
id     : s1270115

*/

#include <stdio.h>
#include <time.h>
#include <math.h>

#define RAND_MAX 2147483647
#define A 48271L
#define M 2147483647L
#define Q (M/A)
#define R (M%A)


int next_rnd2(void);
int next_rnd3(void);
void init_rnd(void);

int cnt[RAND_MAX];
int data[100];

static int a[55];
static int next = 0;
static int x;

void init_rnd(void) {
    int i;
    for(i = 0; i < 55; i++) a[i] = next_rnd2();
}

int my_GetRand(void) { /* Complete Here !!*/
    int i,j;
    i=(next+31) % 55;
    j=(a[i]-a[next]);
    if(j<0){
        j+=2147483647;
        j+=1;
    }
    a[next]=j;
    next=(next+1)%55;
    
    return j%RAND_MAX;
}

int next_rnd2(void) { /* Complete Here !! */ 
    x=A*(x%Q)-R*(x/Q);
    if(x<0) x=x+M;

    return x;
}

void my_srand(void){
    time_t stamp;
    struct tm *t;

    stamp = (int)time(NULL);
    t = localtime(&stamp);

    x = t->tm_sec; //seed according to the current time

    init_rnd();
}
