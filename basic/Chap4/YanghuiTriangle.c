/*
 *This file prints Yanghui Triangle
 *
 */

#include<stdio.h>

static int* printLayer(int layer,int indent);
static void printIndent(int indent);
static int c(int n,int k);
static int c2(int n,int k);

int main()
{
  int layer=6;
  printLayer(layer,0);
  printf("\n");
  printf("Result:%d\n",c(5,2));
  printf("Result:%d\n",c2(5,2));
}

static int* printLayer(int layer,int indent)
{
  if(layer==0)
  {
    printIndent(indent);
    printf("1\n");
    return NULL;
  }

  if(layer==1)
  {
    printLayer(0,indent+1);
    printIndent(indent);
    int* res=(int*)malloc(sizeof(int)*2);
    *res=1;
    *(res+1)=1;
    printf("1 1\n");
    return res;
  }

  int* prev=printLayer(layer-1,indent+1);

  printIndent(indent);
  printf("1");

  int i=1;
  int* orig=(int *)malloc(sizeof(int)*(layer+1));
  int* res=orig;
  *(res++)=1;
  for(;i<layer;i++)
  {
    int current=*(prev+i-1)+*(prev+i);
    *(res++)=current;
    printf(" %d",current);
  }
  
  *res=1;
  printf(" 1\n");
  return orig;  
}

static void printIndent(int indent)
{
  int i=1;
  for(;i<=indent;i++)
  {
    printf(" ");
  }
}

static int c(int n,int k)
{
  if(k==0)
    return 1;
  if(k==1)
    return n;
  if(n==k)
    return 1;
  return c(n-1,k-1)+c(n-1,k);
}

static int c2(int n,int k)
{
  if(k==0)
    return 1;
  if(k==1)
    return n;
  if(n==k)
    return 1;
  int prev=c2(n-1,k-1);
  return prev+prev*(n-k)/k;
}

