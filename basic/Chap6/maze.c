/*
 *maze.c - try to solve a maze
 *
 */

#include "mazelib.h"
#include <stdio.h>

#define ROWS 7
#define COLUMNS 7

static void solveMaze();
static void testRead();
static void testWall();

int setting[ROWS][COLUMNS];
int mark[ROWS][COLUMNS];

int main()
{
  testRead();
  testWall();
}

static void solveMaze()
{
  
}

void ReadMazeMap(string filename)
{
  FILE* file=fopen(filename,"r");
  if(file==NULL)
  {
    printf("Error:cannot open file %s\n",filename);
    exit(1);
  }

  int lineNum=0;
  while(!feof(file))
  {
    fscanf(file,"%d %d %d %d %d %d %d\n",&(setting[lineNum][0]),&(setting[lineNum][1]),
      &setting[lineNum][2],&setting[lineNum][3],&setting[lineNum][4],&setting[lineNum][5],
      &setting[lineNum][6]);
    lineNum++;
    
  }

  fclose(file);
}

pointT GetStartPosition()
{
  pointT start;
  start.x=4;
  start.y=3;
  return start;
}

pointT GetEndPosition()
{
  pointT end;
  end.x=6;
  end.y=3;
  return end;
}

bool OutsideMaze(pointT pt)
{
}

bool WallExists(pointT pt,directionT dir)
{
  int notwall=setting[pt.x][pt.y];
  if(notwall&dir)
    return FALSE;
  return TRUE;
}

void MarkSquare(pointT pt)
{
}

void UnmarkSquare(pointT pt)
{
}

bool isMarked(pointT pt)
{
}

static void testRead()
{
  ReadMazeMap("maze.data");
  int i=0;
  
  for(;i<ROWS;i++)
  {
    int j=0;
    for(;j<COLUMNS;j++)
    {
      printf("%d ",setting[i][j]);
    }
    printf("\n");
  }
}

static void testWall()
{
  pointT cur1;
  cur1.x=0;
  cur1.y=0;
  if(!WallExists(cur1,Left))
    printf("cur1 left wrong\n");
  if(!WallExists(cur1,Up))
    printf("cur1 up wrong\n");
  if(!WallExists(cur1,Right))
    printf("cur1 right wrong\n");
  if(WallExists(cur1,Down))
    printf("cur1 down wrong\n");
}
