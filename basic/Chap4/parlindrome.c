/*
 *This file better determines whether a string is parlindrome
 *
 */

#include<stdio.h>
#include<string.h>
static int isPalindrome(char str[]);
static int checkPalindrome(char str[],int len); 

int main()
{
  char* string="abc";
  if(isPalindrome(string))
    printf("String %s is palindrome\n",string);
  else
    printf("String %s is not palindrome\n",string);
}

static int isPalindrome(char str[])
{
  return checkPalindrome(str,strlen(str));
}

static int checkPalindrome(char str[],int len)
{
  if(len<=1) return 1;
  return str[0]==str[len-1] && checkPalindrome(++str,len-2); //str+1 Ok but str++ is not correct
}
