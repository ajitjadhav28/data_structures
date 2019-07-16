/**
 * @file circularQueue.c
 * @author Ajit Jadhav (mr.ajitjadhav@gmail.com)
 * @brief Circular queue using array
 * @date 04-07-2019
 * @subject Data Structures
 * 
 */

#include "mydef.h"
#define N 5

int q[N], fp=-1, rp=-1;

/**
 * @brief Print current queue elements
 * 
 * @param p poiner to q
 */
void printQueue(int *p)
{
    int i = 0;
    for(; i < N; i++) printf("%d ", p[i]);
    ps("");
}

/**
 * @brief Insert **item** in queue.
 * 
 * @param item 
 */
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

/**
 * @brief Remove item from queue.
 * 
 * @return int 
 */
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
