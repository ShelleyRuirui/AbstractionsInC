/*
 *drawtree.c --- Draw a 
 *
 */

#include<stdio.h>
#include<math.h>
#include "../../util/exception.h"
#include "../../util/graphics.h"
#include "../../util/random.h"

static void drawtree();
static void drawRealTree(double length,int curtheta,int depth);
static double Radians(double degrees);

int theta=20;

int main()
{
  drawtree();
}

static void drawtree()
{
  InitGraphics();
  MovePen(3.0,3.0);
  drawRealTree(1.0,90,0);
}

static void drawRealTree(double length,int curtheta,int depth)
{
  DrawLine(length*cos(Radians(curtheta)),length*sin(Radians(curtheta)));
  if(depth>=15)
    return;
  double currentx=GetCurrentX();
  double currenty=GetCurrentY();

  if(!(depth>=4 && RandomChance(0.5)))
    drawRealTree(length*0.8,curtheta+theta,depth+1);
  if(!(depth>=4 && RandomChance(0.5))){
    MovePen(currentx,currenty);
    drawRealTree(length*0.8,curtheta-theta,depth+1);
  }
}

static double Radians(double degrees)
{
    return (degrees / 180 * 3.1415926535);
}
