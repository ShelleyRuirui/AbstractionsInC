/*
 *
 *
 */

#include<stdio.h>

int * test(int);

int main()
{
  int i=2;
  int* res=test(i);
  int j=0;
  for(;j<=i-1;j++)
  {
    printf("%d ",*(res+j));
  }
  printf("\n");
}

int * test(int i)
{
  if(i==1)
  {
    int* res=(int*)malloc(sizeof(int));
    *res=1;
    return res;
  }

  int* prev=test(i-1);
  int* res=(int*)malloc(sizeof(int)*i);
  int* cur=res;
  int j=0;
  for(;j<i-1;j++)
  {
    *(cur++)=*(prev+j);
  }
  *cur=i;
  return res;
}
