/*
 *This program solves ax^2+bx+c=0
 *
 */

#include <stdio.h>
#include <math.h>
#include "../../util/genlib.h"
#include "../../util/simpio.h"

static void GetCoefficients(double *pa,double *pb,double *pc);
static void SolveQuadratic(double a,double b,double c,double *px1,double *px2);
static void DisplayRoots(double x1,double x2);

/* Main program*/

int main()
{
  double a,b,c,x1,x2;

  GetCoefficients(&a,&b,&c);
  SolveQuadratic(a,b,c,&x1,&x2);
  DisplayRoots(x1,x2);
}

static void GetCoefficients(double *pa,double *pb,double *pc)
{
  printf("Enter coefficients for the quadratic equation:\n");
  printf("a: ");
  *pa=GetReal();
  printf("b: ");
  *pb=GetReal();
  printf("c: ");
  *pc=GetReal();
}

static void SolveQuadratic(double a,double b,double c,double *px1,double *px2)
{
  double disc,sqrtDisc;

  if(a==0) Error("The a must be nonzero");
  disc=b*b-4*a*c;
  if(disc<0) Error("The solutions are complex numbers");
  sqrtDisc=sqrt(disc);
  *px1=(-b+sqrtDisc)/(2*a);
  *px2=(-b-sqrtDisc)/(2*a);
}

static void DisplayRoots(double x1,double x2)
{
  if(x1==x2) printf("There is a double root at %g\n",x1);
  else printf("The roots are %g and %g\n",x1,x2);
}
