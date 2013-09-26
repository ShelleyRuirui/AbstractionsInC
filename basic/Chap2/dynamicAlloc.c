#include<stdio.h>


int main()
{
  double *darray;
  int n=10;
  darray=malloc(n*sizeof(double));
  if(darray==NULL) printf("No memory available");

  typedef struct{
    int i;
    int j;
  }* posT;

  posT pos;
  printf("The size of posT is %ld\n",sizeof(posT));

  double *d1;
  printf("The size of double is %ld\n",sizeof(double));
  printf("The size of double pointer is %ld\n",sizeof(d1));
}
