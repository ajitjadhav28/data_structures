#include "mydef.h"
#define N 5

int q[N], fp=-1, rp=-1;

void printQueue(int *p)
{
    int i = 0;
    for(; i < N; i++) printf("%d ", p[i]);
    ps("");
}

void enqueue(int item)
{
    if((rp + 1) % N == fp){
        printError("Queue Full.");
        exit(1);
    }
    if(rp == N-1) rp = 0;
    else rp++;
    q[rp] = item;
    if(fp == -1) fp++;
}

int dequeue()
{
    int item;
    if(fp == -1){
        printError("Queue Empty");
        exit(1);
    }
    item = q[fp];
    if(fp == rp) fp = rp = -1;
    else if(fp == N-1) fp = 0;
    else fp++;
    return item;
}

int main(int argc, char const *argv[])
{
    int i = 0;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    printf("%d  ", dequeue());
    printf("%d  ", dequeue());
    enqueue(60);
    enqueue(70);
    for(i=0; i < N; i++ ) printf("%d  ", dequeue());
    return 0;
}
