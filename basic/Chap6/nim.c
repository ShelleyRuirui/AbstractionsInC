/*
 * nim.c - Find 
 * -----------
 * Two take 13 coins, lost if take last 
 */

#include <stdio.h>
#include "../../util/genlib.h"
#include "../../util/simpio.h"
#include "../../util/strlib.h"

#define InitialCoins 100
#define MaxTake 3
#define NoGoodMove -1

typedef enum {Human,Computer} playerT;

static void GiveInstructions();
static void AnnounceWinner(int nCoins,playerT whoseTurn);
static int GetUserMove(int nCoins);
static bool MoveIsLegal(int nTaken,int nCoins);
static int ChooseComputerMove(int nCoins);
static int FindGoodMove(int nCoins);
static bool IsBadPosition(int nCoins);

int main()
{
  int nCoins,nTaken;
  playerT whoseTurn;

  GiveInstructions();
  nCoins=InitialCoins;
  whoseTurn=Computer;
  
  while(nCoins>1){
    printf("There are %d coins in the pile.\n",nCoins);
    switch(whoseTurn){
      case Human:
	nTaken=GetUserMove(nCoins);
	whoseTurn=Computer;
	break;
      case Computer:
	nTaken=ChooseComputerMove(nCoins);
	printf("I'wll take %d.\n",nTaken);
	whoseTurn=Human;
	break;
    }
    nCoins-=nTaken;
  }

 AnnounceWinner(nCoins,whoseTurn);
}

static void GiveInstructions(void)
{
  printf("Hello. Welcome to the game. \n");
  printf("You and me take coins, all together 13. Who takes last loses\n");
}

static void AnnounceWinner(int nCoins,playerT whoseTurn)
{
  if(nCoins==0)
    printf("You took the last coin. You lose.\n");
  else{
    printf("There is only one coin left.\n");
    switch(whoseTurn){
      case Human: printf("I win.\n"); break;
      case Computer: printf("I lose.\n"); break;
    }
  }
}
static int GetUserMove(int nCoins)
{
  int nTaken,limit;

  while(TRUE){
    printf("How many would you like? ");
    nTaken=GetInteger();
    if(MoveIsLegal(nTaken,nCoins)) break;
    limit=(nCoins<MaxTake)?nCoins:MaxTake;
    printf("That's cheating! Please choose a number");
    printf(" between 1 and %d.\n",limit);
    printf("There are %d coins in the pile.\n",nCoins);
  }
  return nTaken;
}

static bool MoveIsLegal(int nTaken,int nCoins)
{
  return (nTaken>0 && nTaken<=MaxTake && nTaken<=nCoins);
}

static int ChooseComputerMove(int nCoins)
{
  int nTaken;
  nTaken=FindGoodMove(nCoins);
  if(nTaken==NoGoodMove) nTaken=1;
  return nTaken;
}

static int FindGoodMove(int nCoins)
{
  int nTaken;

  for(nTaken=1;nTaken<=MaxTake;nTaken++){
    if(IsBadPosition(nCoins-nTaken)) return nTaken;
  }
  return NoGoodMove;
}

static bool IsBadPosition(int nCoins)
{
  if(nCoins==1) return TRUE;
  return (FindGoodMove(nCoins)==NoGoodMove);
}
