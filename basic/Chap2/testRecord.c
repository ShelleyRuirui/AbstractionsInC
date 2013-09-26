#include<stdio.h>

int main()
{
  typedef struct{
    int i;
    int j;
  } posT;

  posT pos1;
  pos1.i=1;
  pos1.j=2;

  printf("The i is %d\n",pos1.i);

  //Pointers should first be initialized here or segment fault
  posT pos2;
  posT *ppos=&pos2;
  ppos->i=3;
  printf("The i is %d\n",ppos->i);

  printf("The j is %d\n",ppos->j);//No fault
}
