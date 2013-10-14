/*
 *This program solves the hanoi tower
 *
 */

#include<stdio.h>

static void printSingleStep(int n,char start,char end);
static void moveDisks(int n,char start,char end,char mid);

int main()
{
  moveDisks(3,'A','B','C');
}

static void printSingleStep(int n,char start,char end)
{
  printf("Move disk %d from %c to %c\n",n,start,end);
}

static void moveDisks(int n,char start,char end,char mid)
{
  if(n==1)  printSingleStep(n,start,end);
  else{
    moveDisks(n-1,start,mid,end);
    printSingleStep(n,start,end);
    moveDisks(n-1,mid,end,start);
  }
}
