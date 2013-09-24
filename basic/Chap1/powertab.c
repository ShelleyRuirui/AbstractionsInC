#include <stdio.h>
#include "../../util/genlib.h"

#define LowerLimit 0
#define UpperLimit 12

static int RaiseIntToPower(int n,int k);

int main(){
  int n;

  printf("    |   2|   N\n");
  printf("   N|   N|   2\n");
  printf("----+----+-----\n");
  for(n=LowerLimit;n<=UpperLimit;n++){
    printf(" %2d | %3d | %4d\n",n,RaiseIntToPower(n,2),RaiseIntToPower(2,n));
  }
}

static int RaiseIntToPower(int n,int k)
{
  int i,result;
  result=1;

  for(i=0;i<k;i++){
    result *= n;
  }
  return result;
}
