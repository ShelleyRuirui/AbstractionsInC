/*
 *  This tictac.c file is used for playing tic-tac between user and computer
 *
 *
 *
 */
 
#include <stdio.h>
#include "../../util/genlib.h"
#include "../../util/simpio.h"
#include "../../util/strlib.h"

#define WinningPosition 1000
#define NeutralPosition 0
#define LosingPosition (-WinningPosition)

typedef enum {Human,Computer} playerT;

/*
  1 2 3
  4 5 6
  7 8 9
 */
typedef int moveT;

typedef struct{
  char board[(3*3)+1];
  playerT whoseTurn;
  int turnsTaken;
} STATE;
typedef STATE* stateT;

#define MaxMoves 9

#define MaxDepth 1000

static int winningLines[][3]={
  {1,2,3},
  {4,5,6},
  {7,8,9},
  {1,4,7},
  {2,5,8},
  {3,6,9},
  {1,5,9},
  {3,5,7}
};

static int nWinningLines=sizeof winningLines / sizeof winningLines[0];

static moveT FindBestMove(stateT state,int depth,int *pRating);
static int EvaluatePosition(stateT state,int depth);
static stateT NewGame();
static void DisplayGame(stateT state);
static void DisplayMove(moveT move);
static void GiveInstructions();
static char PlayerMark(playerT player);
static moveT GetUserMove(stateT state);
static bool MoveIsLegal(moveT move,stateT state);
static moveT ChooseComputerMove(stateT state);
static int GenerateMoveList(stateT state,moveT moveArray[]);
static void MakeMove(stateT state,moveT move);
static void RetractMove(stateT state,moveT move);
static void AnnounceResult(stateT state);
static bool GameIsOver(stateT state);
static int EvaluateStaticPosition(stateT state);
static bool CheckForWin(stateT state,playerT player);
static playerT Opponent(playerT player);
static playerT WhoseTurn(stateT state);


int main()
{
  stateT state;
  moveT move;
  
  GiveInstructions();
  state=NewGame();
  while(!(GameIsOver(state))){
    DisplayGame(state);
	switch(WhoseTurn(state)){
	  case Human:
	    move=GetUserMove(state);
	    break;
	  case Computer:
	    move=ChooseComputerMove(state);
	    break;
	}
	MakeMove(state,move);
        //printf("The move is %d\n",move);
  }
  AnnounceResult(state);
}

static moveT FindBestMove(stateT state,int depth,int *pRating)
{
  moveT moveArray[MaxMoves];
  int count=GenerateMoveList(state,moveArray);
  
  moveT move,bestMove=0;
  int rating,minRating;
  int i=0;
  
  if(count==0) Error("No moves available.\n");
  minRating=WinningPosition+1;
  
  for(;i<count && minRating!=LosingPosition;i++){
        move=moveArray[i];
    	MakeMove(state,move);
	//printf("Current move:%d\n",moveArray[i]);
	rating=EvaluatePosition(state,depth+1);
	//Compare
	if(rating<minRating){
	  bestMove=move;
	  minRating=rating;
          //printf("Here updating bestMove %d\n",bestMove);
	}	
	RetractMove(state,moveArray[i]);
  }
  *pRating= -minRating;
  //printf("Computer best move:%d\n",bestMove);
  return bestMove;
}

static int EvaluatePosition(stateT state,int depth)
{
  if( GameIsOver(state) || depth>=MaxDepth){
    return EvaluateStaticPosition(state);
  }
  
  int rating;
  FindBestMove(state,depth,&rating);
  return rating;
}

static stateT NewGame()
{
  stateT state=(stateT)malloc(sizeof(STATE));
  int i=0;
  
  for(i=1;i<=9;i++) state->board[i]=' ';
  state->whoseTurn=Computer;
  state->turnsTaken=0;
  return state;
}

static void DisplayGame(stateT state)
{
  if(GameIsOver(state)){
    printf("\nThe final position looks like this:\n\n");
  }else{
    printf("\nThe game now looks like this:\n\n");
  }
  
  int row=0,col=0;
  for(;row<3;row++){
    if(row!=0) printf("---+---+---\n");
	for(col=0;col<3;col++){
	  if(col!=0) printf("|");
	  printf(" %c ",state->board[row*3+col+1]);
	}
	printf("\n");
  }
  printf("\n");
}

static void DisplayMove(moveT move)
{
}

static void GiveInstructions()
{
  printf("Welcome to tic-tac-toe game\n");
  printf("Computer first\n");
  printf("Your mark is:%c and my mark is %c\n",PlayerMark(Human),PlayerMark(Computer));
}

static char PlayerMark(playerT player)
{
  if(player==Computer) return 'O';
  return 'X';
}

static moveT GetUserMove(stateT state)
{
  printf("Your move.\n");
  int move;
  while(TRUE){
    printf("Which square? ");
	move=GetInteger();
	if(MoveIsLegal(move,state)) break;
	printf("The move is illegal. Try again.\n");
  }
  return move;
}

static bool MoveIsLegal(moveT move,stateT state)
{
  return move>=1 && move<=9 && state->board[move]==' ';
}

static moveT ChooseComputerMove(stateT state)
{
  printf("My move.\n");
  int rating;
  return FindBestMove(state,0,&rating);
}

static int GenerateMoveList(stateT state,moveT moveArray[])
{
  int count=0,i=1;
  for(;i<=9;i++){
    if(state->board[i]==' ')
	  moveArray[count++]=(moveT)i;
  }
  return count;
}

static void MakeMove(stateT state,moveT move)
{
  state->board[move]=PlayerMark(state->whoseTurn);
  state->whoseTurn=Opponent(state->whoseTurn);
  state->turnsTaken++;
}

static void RetractMove(stateT state,moveT move)
{
  state->board[move]=' ';
  state->whoseTurn=Opponent(state->whoseTurn);
  state->turnsTaken--;
}

static void AnnounceResult(stateT state)
{
  DisplayGame(state);
  if(CheckForWin(state,Human))
    printf("You win.\n");
  else if(CheckForWin(state,Computer))
    printf("I win.\n");
  else
    printf("Tie.\n");
}

static bool GameIsOver(stateT state)
{  //Either the board is filled or someone has won
  return state->turnsTaken==9 || CheckForWin(state,state->whoseTurn) || CheckForWin(state,Opponent(state->whoseTurn));
}

static int EvaluateStaticPosition(stateT state)
{
  if(CheckForWin(state,state->whoseTurn))
    return WinningPosition;
  if(CheckForWin(state,Opponent(state->whoseTurn)))
    return LosingPosition;
  return NeutralPosition;
}

static bool CheckForWin(stateT state,playerT player)
{
  if(state->turnsTaken<5) return FALSE;
  char mark;
  int i=0;
  mark=PlayerMark(player);
  for(;i<nWinningLines;i++){
    if(mark==state->board[winningLines[i][0]] && mark==state->board[winningLines[i][1]] && mark==state->board[winningLines[i][2]])
	  return TRUE;
  }
  return FALSE;
}

static playerT Opponent(playerT player)
{
  switch(player){
    case Human: return Computer;
    case Computer: return Human;
  }
}

static playerT WhoseTurn(stateT state)
{
  return state->whoseTurn;
}
