/*
 *Usage of array
 *
 */

#include <stdio.h>
#include "../../util/genlib.h"
#include "../../util/simpio.h"

#define MaxJudges 100
#define MinScore 0.0
#define MaxScore 10.0

static void ReadAllScores(double scores[],int nJudges);
static double GetScore(int judge);
static double Mean(double array[],int n);

int main()
{
  double scores[MaxJudges];
  int nJudges;

  printf("Enter the number of judges: ");
  nJudges=GetInteger();
  if(nJudges>MaxJudges) Error("Too many judges");
  ReadAllScores(scores,nJudges);
  printf("The average score is %.2f\n",Mean(scores,nJudges));
}

static void ReadAllScores(double scores[],int nJudges)
{
  int i;

  for(i=0;i<nJudges;i++){
    scores[i]=GetScore(i);
  }
}

static double GetScore(int judge)
{
  double score;
  while(TRUE){
    printf("Score for judge #%d: ",judge);
    score=GetReal();
    if(score>=MinScore && score<=MaxScore) break;
    printf("That score is out of range. Try again.\n");
  }
  return score;
}

static double Mean(double array[],int n)
{
  int i;
  double total=0;
  for(i=0;i<n;i++){
    total+=array[i];
  }
  return total/n;
}

