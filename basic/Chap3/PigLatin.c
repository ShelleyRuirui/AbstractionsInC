/*
 *Use string.h
 *
 */

#include<string.h>
#include<stdio.h>

#define MaxWord 100

typedef char * string;

static int IsVowel(char c)
{
  if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return 1;
  return 0;
}

static char* FindFirstVowel(char* word)
{
  char *cp;
  for(cp=word;*cp !='\0';cp++){
    if(IsVowel(*cp)) return cp;
  }
  return NULL;
}

static void PigLatin(char *word,char buffer[],int bufferSize)
{
  char *vp;
  int wordLength;

  vp=FindFirstVowel(word);
  wordLength=strlen(word);
  if(vp==word) wordLength+=3;
  else if(vp!=NULL) wordLength+=2;

  if(wordLength>=bufferSize) {printf("Buffer overflow");return;}
  if(vp==NULL) strcpy(buffer,word);
  else if (vp==word){
    strcpy(buffer,word);
    strcat(buffer,"way");
  }else{
    strcpy(buffer,vp);
    strncat(buffer,word,vp-word);
    strcat(buffer,"ay");
  }

}

int main()
{
  char word[MaxWord+1];
  char buffer[MaxWord+1];

  printf("Enter a word: ");
  gets(word);
  PigLatin(word,buffer,MaxWord+1);
  printf("Pig Latin:%s \n",buffer);
}
