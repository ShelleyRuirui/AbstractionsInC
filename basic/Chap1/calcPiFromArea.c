#include <stdio.h>
#include <math.h>

#define CALCCOUNT 10000000

int main()
{
  double radius=2.0;
  double w=radius/CALCCOUNT;
  double area=0.0;
  double currentw=0.0;
  int i;
  for(i=0;i<CALCCOUNT;i++){
    double h=sqrt(pow(radius,2)-pow(currentw,2));
    area+= h*w;
    currentw += w;
  }
  printf("The result of PI is %.10f\n",area);
}
