// Author: Ajit J.
// Subject: Data Structures
// Desc: Implimentation of linear queue using array.

#include "mydef.h"
#define N 5

int q[N], fp=-1, rp=-1;

void enqueue(int item)
{
    if(rp == N-1){
        printError("Queue Full.");
        exit(1);
    }
    q[++rp] = item;
    if(fp == -1)
        fp++;
}

int dequeue()
{
    int item;
    if(fp == -1){
        printError("Queue Empty");
        exit(1);
    }
    item = q[fp];
    if(fp == rp)
        fp = rp = -1;
    else
        fp++;
    return item;
}

int main(int argc, char const *argv[])
{
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        if( i < 5) enqueue(i);
        else printf("%d ", dequeue());
    }
    return 0;
}
