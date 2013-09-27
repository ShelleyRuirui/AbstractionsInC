/*
 *Test the use of string.h and strlib.h
 *
 */

#include <string.h>

#define BufferSize 10

int main()
{
  char* src="Hello";
  char dst[BufferSize];

  strcpy(dst,src);

  printf("The dst string is %s\n",dst);
}
