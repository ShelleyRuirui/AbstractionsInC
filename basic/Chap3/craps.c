/*
 *a casino game
 */

#include <stdio.h>
#include "../../util/genlib.h"
#include "../../util/random.h"

static int TryToMakePoint(int point);
static int RollTwoDice(void);

int main()
{
  int point;

  Randomize();
  printf("This program plays a game of craps.\n");
  point=RollTwoDice();
  switch(point){
    case 7: case 11:
      printf("That's a natural. You win\n");
      break;
    case 2: case 3: case 12:
      printf("That's craps. You lose.\n");
      break;
    default:
      printf("Your point is %d.\n",point);
      if(TryToMakePoint(point)) printf("You made your point.  You win.\n");
      else printf("You rolled a seven. You lose.\n");
  }
}

static int TryToMakePoint(int point)
{
  int total;

  while(TRUE){
    total=RollTwoDice();
    if(total==point) return (TRUE);
    if(total==7) return FALSE;
  }
}

static int RollTwoDice(void)
{
  int d1,d2,total;

  printf("Rolling the dice . . .\n");
  d1=RandomInteger(1,6);
  d2=RandomInteger(1,6);
  total=d1+d2;
  printf("You rolled %d and %d -- that's %d.\n",d1,d2,total);
  return total;
}
