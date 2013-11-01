/*
 *maze.c - try to solve a maze
 *
 */

#include "mazelib.h"
#include <stdio.h>

#define ROWS 7
#define COLUMNS 7

static bool solveMaze(pointT current);
static bool solveOneDir(pointT current,pointT next,directionT dir);
static void printMark();
static void testRead();
static void testWall();
static void initMarks();

int setting[ROWS][COLUMNS];
int mark[ROWS][COLUMNS];
pointT start;
pointT end;

int main()
{
  //testRead();
  //testWall();
  initMarks();
  ReadMazeMap("maze.data");
  start=GetStartPosition();
  end=GetEndPosition();
   mark[start.x][start.y]=1;
  bool res=solveMaze(start);
  printf("Result:%d\n",res);
  printMark();
}

static bool solveMaze(pointT current)
{
  if(current.x==end.x && current.y==end.y)
  {
    return TRUE;
  }

  pointT next;
  next.x=current.x;
  next.y=current.y-1; 
  bool res=solveOneDir(current,next,Left);
  if(res) return TRUE;

  next.x=current.x-1;
  next.y=current.y;
  res=solveOneDir(current,next,Up);
  if(res) return TRUE;

  next.x=current.x;
  next.y=current.y+1;
  res=solveOneDir(current,next,Right);
  if(res) return TRUE;
  
  next.x=current.x+1;
  next.y=current.y;
  res=solveOneDir(current,next,Down);
  if(res) return TRUE;

  return FALSE;
}

static bool solveOneDir(pointT current,pointT next,directionT dir)
{
  if(!WallExists(current,dir) && next.y>=0 && next.x>=0 && next.x<ROWS && next.y<COLUMNS && !isMarked(next))
  {
    MarkSquare(next);
    //printMark();
    bool res=solveMaze(next);
    
    if(res) return TRUE;
    UnmarkSquare(next);
  }
  return FALSE;
}

static void initMarks()
{
  int i=0;
  int j;
  for(;i<ROWS;i++)
  {
    for(j=0;j<COLUMNS;j++)
    {
      mark[i][j]=0;
    }
  }
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
  mark[pt.x][pt.y]=1;
}

void UnmarkSquare(pointT pt)
{
  mark[pt.x][pt.y]=0;
}

bool isMarked(pointT pt)
{
  if(mark[pt.x][pt.y]==1)
    return TRUE;
  return FALSE;
}

static void printMark()
{
  printf("**********\n");
  int i=0;
  int j;
  for(;i<ROWS;i++)
  {
    for(j=0;j<COLUMNS;j++)
    {
      printf("%d ",mark[i][j]);
    }
    printf("\n");
  }
  printf("**********\n");
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

  cur1.x=2;
  cur1.y=4;
  if(!WallExists(cur1,Right))
    printf("cur1 2 Right wrong\n");
}
