/*
 * DrawFractals.c --- draw the recursive triangle 
 *
 */
#include<stdio.h>
#include<math.h>
#include "../../util/exception.h"
#include "../../util/graphics.h"

static void drawTriangle(double length,int depth);
static void drawEdge(double length,int depth,int theta);
static double Radians(double degrees);

int main()
{
  InitGraphics();
  MovePen(5.0,5.0);
  drawTriangle(2.0,3);
}

static void drawTriangle(double length,int depth)
{
  int theta=-120;
  drawEdge(length,depth,theta);
  theta=0;
  drawEdge(length,depth,theta);
  theta=120;
  drawEdge(length,depth,theta);
}

static void drawEdge(double length,int depth,int theta)
{
  if(depth==0){
    DrawLine(length*cos(Radians(theta)),length*sin(Radians(theta)));
  }else{
    drawEdge(length/3,depth-1,theta);
    theta=theta-60;
    drawEdge(length/3,depth-1,theta);
    theta=theta+120;
    drawEdge(length/3,depth-1,theta);
    theta=theta-60;
    drawEdge(length/3,depth-1,theta);
  }
}

static double Radians(double degrees)
{
    return (degrees / 180 * 3.1415926535);
}
