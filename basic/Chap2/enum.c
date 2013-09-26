#include <stdio.h>

typedef enum {January=1,February,March,April,May} monthT;
typedef enum {North,East,South,West} directionT;

directionT RightFrom(directionT dir);
char* DirectionName(directionT dir);

int main()
{
  typedef enum {Red,Green,Blue,Yellow,Cyan,Magenta} colorT;
  directionT dir=RightFrom(East);
  printf("The direction is %s\n",DirectionName(dir));

  for(dir=North;dir<=West;dir++){
    printf("Current direction is %s\n",DirectionName(dir));
  }
}

directionT RightFrom(directionT dir)
{
  return ((dir+1)%4);
}

char* DirectionName(directionT dir)
{
  switch(dir){
    case North:return "North";
    case East:return "East";
    case South:return "South";
    case West:return "West";
    default: printf("Illegal direction value\n");
	return "";
  }
}
