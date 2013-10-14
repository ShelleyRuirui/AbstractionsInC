#include<stdio.h>
#include<string.h>

static void permute(char* str,int k);

int main()
{
  char test[5];
  strcpy(test,"abc");
  permute(test,0);
}

static void permute(char* str,int k)
{
  int length=strlen(str);
  if(k==length){
    printf("%s\n",str);
    return;
  }else{    
    permute(str,k+1);
    int i=k+1;
    char front=str[k];
    for(;i<length;i++){
      str[k]=str[i];
      str[i]=front;
      permute(str,k+1);
      str[i]=str[k];
      str[k]=front;
    }
  }
}
