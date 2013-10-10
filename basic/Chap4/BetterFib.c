/*
 *This file implements a more efficient Fib algo than straw one
 *
 */
#include<stdio.h>

static int efficientFib(int n,int i1,int i2);
static int fib(int n);


int main()
{
  int n=9;
  printf("The %dth number of fib is %d\n",n,fib(n));
}

static int fib(int n)
{
  return efficientFib(n,1,1);
}

static int efficientFib(int n,int i1,int i2)
{
  if(n==0) return i1;
  if(n==1) return i2;
  return efficientFib(n-1,i2,i1+i2);
}
