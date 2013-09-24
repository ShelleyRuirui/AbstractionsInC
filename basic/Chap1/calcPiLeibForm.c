#include <stdio.h>

#define CALCCOUNT 10000000


int main()
{
  int i;
  double qresult=0.0;
  char sign='+';
  for(i=0;i<CALCCOUNT;i++){
    switch(sign){
      case '+': qresult += (1.0/(2*i+1));
		sign='-';
		break;	
      case '-': qresult -= (1.0/(2*i+1));	
		sign='+';
		break;	
    }
  }
  qresult *=4;
  printf("The result of PI is %.10f\n",qresult);
}
