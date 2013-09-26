#include<stdio.h>
int main()
{
  double nums[]={1.0,2.0,3.0,4.0};
  double *p=&nums[0];
  printf("The second number is:%g \n",*(p+1));
}
